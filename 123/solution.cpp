class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i=1; i<3; i++) {
            int localMax = dp[0] - prices[0];
            for (int j=1; j<n; j++) {
                int tmp = dp[j];
                dp[j] = max(dp[j-1], localMax + prices[j]);
                localMax = max(localMax, tmp-prices[j]);
            }
        }
        return dp[n-1];
        // vector<vector<int>> dp(3, vector<int>(n, 0));
        // for (int i=1; i<3; i++) {
        //     int localMax = dp[i-1][0] - prices[0];
        //     for (int j=1; j<n; j++) {
        //         dp[i][j] = max(dp[i][j-1], localMax + prices[j]);
        //         localMax = max(localMax, dp[i-1][j] - prices[j]);
        //     }
        // }
        
        // return dp[2][n-1];
    }
};