class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), gap = n-4;
        if (n <= 4) return 0;
        int diff = INT_MAX;
        for (int i=0; i+gap<n; i++) {
            diff = min(diff, nums[i+gap] - nums[i]);
        }
        return diff;
    }
};