class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = searching(nums, target);
        int secondIdx = searching(nums, target+1)-1;
        if (firstIdx < nums.size() && nums[firstIdx] == target) {
            return {firstIdx, secondIdx};
        } else {
            return {-1, -1};
        }
    }
    
    int searching(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int mid = (j-i)/2 + i;
            if (nums[mid] < target) i = mid+1;
            else {
                j = mid-1;
            } 
        }
        return i;
    }
};