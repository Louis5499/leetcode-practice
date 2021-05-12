class Solution {
private:
    int robbery(vector<int>& nums, int l, int r) {
        int prev = 0;
        int cur = 0;
        for (int i=l; i<=r; i++) {
            int tmp = cur;
            cur = max(cur, prev + nums[i]);
            prev = tmp;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() <= 1) return nums[0];
        return max(robbery(nums, 0, n- 2), robbery(nums, 1, n - 1));
    }
};