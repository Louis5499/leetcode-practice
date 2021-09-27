class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, 0)));
        int maxResult = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j]) {
                    for (int k=0; k<4; k++) dp[i][j][k] = 1;
                    if (j > 0) dp[i][j][0] += dp[i][j-1][0]; // horizontal line
                    if (j > 0 && i > 0) dp[i][j][1] += dp[i-1][j-1][1]; // anti-diagonal line
                    if (i > 0) dp[i][j][2] += dp[i-1][j][2]; // vertical line
                    if (j < m-1 && i > 0) dp[i][j][3] += dp[i-1][j+1][3]; // diagonal line
                    
                    maxResult = max({ dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3], maxResult });
                }
            }
        }
        
        return maxResult;
    }
};