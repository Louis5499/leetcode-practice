class Solution {
public:
    
    int dp[31][31][31];
    
    bool solve(string &s1, int l1, string &s2, int l2, int len) {
        if (dp[l1][l2][len] != -1) return dp[l1][l2][len];
        
        bool isSame = true;
        int cnt[26] = {0};
        for (int i=0; i<len; i++) {
            if (s1[l1 + i] != s2[l2 + i]) isSame = false;
            cnt[s1[l1 + i] - 'a']++;
            cnt[s2[l2 + i] - 'a']--;
        }
        
        if (isSame) {
            return (dp[l1][l2][len] = true);
        }
        for (int i=0; i<26; i++) {
            if (cnt[i]) {
                return (dp[l1][l2][len] = false);
            }
        }
        
        for (int i=1; i<len; i++) {
            if (solve(s1, l1, s2, l2, i) && solve(s1, l1 + i, s2, l2 + i, len - i)) return (dp[l1][l2][len] = true);
            if (solve(s1, l1 + i, s2, l2, len - i) && solve(s1, l1, s2, l2 + len - i, i)) return (dp[l1][l2][len] = true);
        }
        
        return (dp[l1][l2][len] = false);
    }

    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, 0, s2, 0, s1.length());
    }

};