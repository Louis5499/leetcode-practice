class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxVal = INT_MIN;
        if (nums[0] < 0 && nums[1] < 0) {
            maxVal = max(maxVal, nums[0]*nums[1]*nums.back());
        }
        maxVal = max(maxVal, nums[n-1]*nums[n-2]*nums[n-3]);
        return maxVal;
    }
};