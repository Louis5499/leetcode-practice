class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        const int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> dp(d, vector<int>(n, 0));
        
        dp[0][0] = jobDifficulty[0];
        for (int i=1; i<n; i++) {
            dp[0][i] = max(jobDifficulty[i], dp[0][i-1]);
        }
        
        for (int day=1; day<d; day++) {
            for (int len=day; len<n; len++) {
                int localMax = jobDifficulty[len];
                dp[day][len] = INT_MAX;
                for (int sche = len; sche >= day; --sche) {
                    localMax = max(localMax, jobDifficulty[sche]);
                    dp[day][len] = min(dp[day][len], dp[day-1][sche-1] + localMax);
                }
            }
        }
        
        return dp[d-1][n-1];
        
    }
};