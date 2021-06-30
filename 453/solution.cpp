class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = nums[0], res = 0;
        for (int num: nums) minVal = min(minVal, num);
        for (int num: nums) res += num - minVal;
        return res;
    }
};