class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1]; 
        });
        
        int total = 0;
        for (int i=0; i<boxTypes.size() & truckSize > 0; i++) {
            int numOfBox = min(truckSize, boxTypes[i][0]);
            total += numOfBox*boxTypes[i][1];
            truckSize -= numOfBox;
        }
        
        return total;
    }
};