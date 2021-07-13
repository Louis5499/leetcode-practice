class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int res[2] = {0};
        for (int i=0; i<nums.size(); i++) {
            int left = i > 0 ? nums[i-1] : 1001;
            int right = i < nums.size()-1 ? nums[i+1] : 1001;
            res[i%2] += max(0, nums[i] - min(left, right) + 1);
        }
        return min(res[0], res[1]);
    }
};