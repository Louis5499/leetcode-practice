class Solution {
public:
    // Try to formalize to 2sum
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i=0; i<nums.size(); i++) {
            int remainingTarget = target - nums[i];
            for (int j=i+1; j<nums.size(); j++) {
                int remainingSecondTarget = remainingTarget - nums[j];
                int left = j+1;
                int right = nums.size() - 1;
                
                // 2sum structure
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum < remainingSecondTarget) left++;
                    else if (sum > remainingSecondTarget) right--;
                    else {
                        vector<int> ans(4, 0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[left];
                        ans[3] = nums[right];
                        
                        result.push_back(ans);
                        
                        // Skip duplicated numbers
                        while(nums[left] == ans[2] && left < right) left++;
                        while(nums[right] == ans[3] && left < right) right--;
                    }
                }
                // Skip duplicated numbers
                while(j < nums.size() - 1 && nums[j] == nums[j+1]) j++;
            }
            // Skip duplicated numbers
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        
        return result;
    }
};