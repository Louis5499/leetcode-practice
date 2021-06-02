class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        for (int j=2; j<m+1; j+=2) {
            if (dp[0][j-2] && p[j-1] == '*') dp[0][j] = true; // #*#*#*#*#*#*#*#*#*
        }
        
        for (int i=1; i<n+1; i++) {
            for (int j=1; j<m+1; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*'){
                    if (s[i-1] != p[j-2] && p[j-2] != '.') dp[i][j] = dp[i][j-2]; // (Repeat 0 time)
                    else {
                        dp[i][j] = (dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j]); // (Repeat 0 time || Repeat 1 time || Repear n times)
                    }
                }
            }
        }
        return dp[n][m];
    }
};