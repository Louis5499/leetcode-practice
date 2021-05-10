class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxProf = dp[0];
        
        for (int i=1; i<nums.size(); i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            maxProf = max(dp[i], maxProf);
        }
        
        return maxProf;
    }
};