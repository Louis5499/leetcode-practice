class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        for (int i=1; i<nums.size(); i++) nums[i] += nums[i-1];
        int res = nums[firstLen+secondLen-1], lMax = nums[firstLen-1], mMax = nums[secondLen-1];
        for (int i=firstLen+secondLen; i < nums.size(); i++) {
            lMax = max(lMax, nums[i-secondLen] - nums[i-secondLen-firstLen]);
            mMax = max(mMax, nums[i-firstLen] - nums[i-secondLen-firstLen]);
            res = max(res, max(lMax + nums[i] - nums[i-secondLen], mMax + nums[i] - nums[i-firstLen]));
        }
        return res;
    }
};