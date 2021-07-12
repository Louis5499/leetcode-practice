class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<int> dp;
        
        for (vector<int> &env: envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), env[1]);
            if (it == dp.end()) dp.push_back(env[1]);
            else *it = env[1];
        }
        
        return dp.size();
    }
};