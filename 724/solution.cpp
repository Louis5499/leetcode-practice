class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for (int i=1; i<nums.size(); i++) rightSum += nums[i];
        int i=0;
        while (leftSum != rightSum && i < nums.size()) {
            leftSum += nums[i];
            rightSum -= nums[i+1];
            i++;
        }
        return leftSum == rightSum ? i : -1;
    }
};