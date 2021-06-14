class UndergroundSystem {
public:
    map<int, pair<string, int>> startStation;
    map<string, map<string, pair<int, int>>> count;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        startStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> lastStart = startStation[id];
        pair<int, int> &travelInfo = count[lastStart.first][stationName];
        travelInfo.first++; // Count
        travelInfo.second += t - lastStart.second; // Sum
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> &travelInfo = count[startStation][endStation];
        return (double) travelInfo.second / travelInfo.first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */