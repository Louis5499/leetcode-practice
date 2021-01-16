class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return recur(nums, memo, nums.size() - 1);
    }
    
    int recur(vector<int>& nums, vector<int>& memo, int idx) {
        if (idx < 0) return 0;
        if (memo[idx] >= 0) return memo[idx];
        int result = max(recur(nums, memo, idx-1), recur(nums, memo, idx-2) + nums[idx]);
        memo[idx] = result;
        return result;
    }
};