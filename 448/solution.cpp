class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Cyclic sort
        int i = 0, n = nums.size();
        while(i < n) {
            int j = nums[i] - 1;
            if(j < n && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            }
            else {
                ++i;
            }
        }

        // Find all missing number 
        vector<int> missed;
        for(int i = 0; i < n; ++i) {
            if(nums[i] != i + 1) {
                missed.push_back(i + 1);
            }
        }

        return missed;
    }
};