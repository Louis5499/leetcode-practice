class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int totalCost = 0;
        for (int i=1; i<s.length(); i++) {
            int minCost = cost[i-1];
            int maxCost = cost[i-1];
            while (s[i] == s[i-1]) {
                totalCost += min(maxCost, cost[i]);
                maxCost = max(maxCost, cost[i++]);
            }
        }
        return totalCost;
    }
};