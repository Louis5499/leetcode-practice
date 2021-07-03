class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output;
        for (int i=0; i<nums.size(); i++) {
            while (nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) output.emplace_back(nums[i]);
        }
        return output;
    }
};