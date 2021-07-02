class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output;
        int midVal = INT_MAX, mid = 0;
        for (int i=0; i<nums.size(); i++) {
            if (abs(nums[i]) < abs(midVal)) {
                midVal = nums[i];
                mid = i;
            }
        }
        
        int i=mid, j=mid+1;
        while (i >= 0 && j < nums.size()) {
            if (abs(nums[i]) > abs(nums[j])) {
                output.emplace_back(pow(nums[j++], 2));
            } else {
                output.emplace_back(pow(nums[i--], 2));
            }
        }
        while (i >= 0) output.emplace_back(pow(nums[i--], 2));
        while (j < nums.size()) output.emplace_back(pow(nums[j++], 2));
        
        return output;
    }
};