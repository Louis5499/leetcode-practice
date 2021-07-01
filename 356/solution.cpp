class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        int maxVal = INT_MIN, minVal = INT_MAX;
        unordered_set<string> pool;
        for (vector<int> &p: points) {
            minVal = min(minVal, p[0]);
            maxVal = max(maxVal, p[0]);
            pool.insert(to_string(p[0]) + "a" + to_string(p[1]));
        }
        int sum = minVal + maxVal;
        for (vector<int> &p: points) {
            string wantStr = to_string(sum-p[0]) + "a" + to_string(p[1]);
            if (pool.count(wantStr) == 0) return false;
        }
        return true;
    }
};