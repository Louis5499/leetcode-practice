class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, res=0, minInterval = INT_MAX;
        while (j < nums.size()) {
            res += nums[j++];
            
            while (res >= target) {
                minInterval = min(minInterval, j-i);
                res -= nums[i++];
            }
        }
        return minInterval == INT_MAX ? 0 : minInterval;
    }
};