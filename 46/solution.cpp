class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        run(nums, output, 0);
        return output;
    }
    
    void run(vector<int>& nums, vector<vector<int>> &output, int left) {
        if (left == nums.size()-1) {
            output.push_back(nums);
            return;
        }
        for (int i=left; i<nums.size(); i++) {
            swap(nums[left], nums[i]);
            run(nums, output, left+1);
            swap(nums[i], nums[left]);
        }
    }
};