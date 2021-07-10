class Solution {
public:
    const int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, int> pool;
        int n = arr.size();
        vector<long> dp(n, 0);
        sort(arr.begin(), arr.end());
        
        for (int i=0; i<arr.size(); i++) {
            pool[arr[i]] = i;
            dp[i] = 1;
        }
        
        for (int i=0; i<n; i++) {
            int realNum = arr[i];
            for (auto it = pool.begin(); it != pool.end() && it->first < realNum; it++) {
                if (realNum % it->first == 0 && pool.count(realNum/it->first)) {
                    dp[i] = (dp[i] + dp[pool[it->first]] * dp[pool[realNum/it->first]])%mod;
                }
            }
        }
        
        long output = 0;
        for (auto num: dp) output += num;
        return output%mod;
    }
};