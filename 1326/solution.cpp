class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, n+2);
        dp[0] = 0;
        for (int i=0; i<=n; i++) {
            for (int j = max(i - ranges[i]+1, 0); j <= min(i+ranges[i], n); j++) {
                dp[j] = min(dp[j], dp[max(i-ranges[i], 0)]+1);
            }
        }
        return dp[n] < n+2 ? dp[n] : -1;
    }
};