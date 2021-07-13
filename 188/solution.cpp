class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if (k >= prices.size()/2) {
            int maxProf = 0;
            for (int i=1; i<n; i++) {
                if (prices[i] > prices[i-1]) maxProf += prices[i] - prices[i-1];
            }
            return maxProf;
        }
        
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        for (int i=1; i<=k; i++) {
            int localMax = dp[i][0] - prices[0];
            for (int j=1; j<n; j++) {
                dp[i][j] = max(dp[i][j-1], localMax + prices[j]);
                localMax = max(localMax, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
};