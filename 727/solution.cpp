class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<int> dp(m, -1);
        
        for (int i=0; i<m; i++) {
            if (s1[i] == s2[0]) dp[i] = i;
        }
        
        for (int j=1; j<n; j++) {
            int k = -1;
            vector<int> tmp(m, -1);
            for (int i=0; i<m; i++) {
                if (k != -1 && s1[i] == s2[j]) tmp[i] = k;
                if (dp[i] != -1) k = dp[i];
            }
            swap(tmp, dp);
        }
        int st = -1, len = INT_MAX;
        for (int i=0; i<m; i++) {
            if (dp[i] != -1 && i-dp[i]+1 < len) {
                st = dp[i];
                len = i-dp[i]+1;
            }
        }
        return st == -1 ? "" : s1.substr(st, len);
        
//         vector<vector<int>> dp(n, vector<int>(m, -1));
        
//         for (int i=0; i<m; i++) {
//             if (s1[i] == s2[0]) dp[0][i] = i;
//         }
        
//         for (int j=1; j<n; j++) {
//             int k = -1;
//             for (int i=0; i<m; i++) {
//                 if (k != -1 && s1[i] == s2[j]) dp[j][i] = k;
//                 if (dp[j-1][i] != -1) k = dp[j-1][i];
//             }
//         }
//         int st = -1, len = INT_MAX;
//         for (int i=0; i<m; i++) {
//             if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
//                 st = dp[n-1][i];
//                 len = i-dp[n-1][i]+1;
//             }
//         }
//         return st == -1 ? "" : s1.substr(st, len);
    }
};