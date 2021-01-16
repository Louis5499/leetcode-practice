class Solution {
public:
    // int rob(vector<int>& nums) {
    //     if (nums.size() == 0) return 0;
    //     vector<int> memo(nums.size() + 1, -1);
    //     memo[0] = 0;
    //     memo[1] = nums[0];
    //     for (int i=1; i<nums.size(); i++) {
    //         memo[i+1] = max(memo[i], memo[i-1] + nums[i]);
    //     }
    //     return memo[nums.size()];
    // }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> memo(nums.size() + 1, -1);
        int prev = 0;
        int cur = nums[0];
        for (int i=1; i<nums.size(); i++) {
            int tmp = cur;
            cur = max(cur, prev + nums[i]);
            prev = tmp;
        }
        return cur;
    }
};