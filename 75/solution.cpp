class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid = 0;
        while (mid <= right) {
            if (nums[mid] == 0) swap(nums[left++], nums[mid++]);
            else if (nums[mid] == 2) swap(nums[right--], nums[mid]);
            else mid++;
        }
    }
};