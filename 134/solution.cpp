class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startPoint = 0, startSum = 0, sum=0;
        for (int i=0; i<gas.size(); i++) {
            sum += gas[i]-cost[i];
            startSum += gas[i]-cost[i];
            
            if (startSum < 0) {
                startPoint = i+1;
                startSum = 0;
            }
        }
        return sum >= 0 ? startPoint : -1;
    }
};