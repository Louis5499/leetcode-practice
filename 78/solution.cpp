class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        backtracking(output, nums, vector<int>(), 0);
        return output;
    }
    
    void backtracking(vector<vector<int>>& output, vector<int>& nums, vector<int> tmp, int start) {
        output.emplace_back(tmp);
        for (int i=start; i<nums.size(); i++) {
            tmp.emplace_back(nums[i]);
            backtracking(output, nums, tmp, i+1);
            tmp.pop_back();
        }
    }
};