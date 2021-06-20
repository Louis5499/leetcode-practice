class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int runningSum = 0;
        for (int i=0; i<nums.size(); i++) {
            runningSum += nums[i];
            if (k != 0) runningSum %= k;
            if (m.find(runningSum) != m.end()) {
                if (i - m[runningSum] > 1) return true;
            } else m[runningSum] = i;
        }
        return false;
    }
};