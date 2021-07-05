class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int res = 0;
        for (int i=0; i<dp.size(); i++) {
            for (int j=0; j<dp[0].size(); j++) {
                if (dp[i][j] && i && j) {
                    dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + dp[i][j];
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};