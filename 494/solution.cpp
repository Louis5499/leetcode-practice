class Solution {
public:
    map<pair<int,int>,int> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
    int dfs(vector<int>& nums, int target, int i, int sum) {
        if (i == nums.size()) {
            return target == sum;
        }
        if (dp.find(make_pair(i, sum)) != dp.end()) return dp[make_pair(i, sum)];
        int total = 0;
        total += dfs(nums, target, i+1, sum + nums[i]);
        total += dfs(nums, target, i+1, sum - nums[i]);
        dp[make_pair(i, sum)] = total;
        return total;
    }
};