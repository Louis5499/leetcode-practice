class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<unsigned long long> cur(m+1, 0);
        cur[0] = 1;
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            int lastTmp = 1;
            for (int i = 1; i <= m; i++) {
                tmp = cur[i]; 
                cur[i] = cur[i] + (t[i - 1] == s[j - 1] ? lastTmp : 0);
                lastTmp = tmp;
            }
        }
        return cur[m];
    }
};