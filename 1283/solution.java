package com.codesignal.tickets;

import com.codesignal.services.AirlinesInfoServices;
import java.util.List;
import java.util.ArrayList;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

// Init Finding price function as a thread to parallelize searching
class FindingProcess extends Thread {
    private final AirlinesInfoServices airlinesInfoServices;
    private String airline;
    private String originAirport;
    private String destinationAirport;
    private int price;
    
    public FindingProcess(AirlinesInfoServices airlinesInfoServices, String airline, String originAirport, String destinationAirport) {
        this.airlinesInfoServices = airlinesInfoServices;
        this.airline = airline;
        this.originAirport = originAirport;
        this.destinationAirport = destinationAirport;
        this.price = Integer.MAX_VALUE;
    }

    @Override
    public void run() {
        int price = this.airlinesInfoServices.getTicketPrice(this.airline, this.originAirport, this.destinationAirport);
        this.price = price;
    }
    
    public int getValue() {
        return this.price;
    }
}

class PriceTrackerImpl implements PriceTracker {

    private final AirlinesInfoServices airlinesInfoServices;

    public PriceTrackerImpl(AirlinesInfoServices airlinesInfoServices) {
        this.airlinesInfoServices = airlinesInfoServices;
    }

    @Override
    public int getCheapestTicketPrice(String originAirport, String destinationAirport) {
        // Fetch the airlines infomation
        int cheapestPrice = Integer.MAX_VALUE;
        List<String> airlines = this.airlinesInfoServices.getAvailableAirlines();
        
        // Init the threads to parallelize quering
        List<FindingProcess> threads = new ArrayList<FindingProcess>();
        ExecutorService es = Executors.newCachedThreadPool();
        for (String airline: airlines) {
            FindingProcess newThread = new FindingProcess(this.airlinesInfoServices, airline, originAirport, destinationAirport);
            threads.add(newThread);
            es.execute(newThread);
        }
        es.shutdown();
        
        // Aggregate the result at the end
        try {
            es.awaitTermination(150, TimeUnit.MILLISECONDS);
            for (FindingProcess t: threads) {
                int price = t.getValue();
                if (price < cheapestPrice && price != -1 && price != Integer.MAX_VALUE) {
                    cheapestPrice = price;
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        return cheapestPrice == Integer.MAX_VALUE ? -1 : cheapestPrice;
    }
}
