class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long int> targetNums(target + 1, 0);
        
        // for (int i=0; i<nums.size(); i++) {
        //     if (target < nums[i]) continue;
        //     targetNums[nums[i]] = 1;
        // }
        targetNums[0] = 1;
        for (int goal=1; goal<=target;goal++) {
            for (int i=0; i<nums.size(); i++) {
                int remaining = goal - nums[i];
                if (remaining < 0) continue;
                targetNums[goal] += targetNums[remaining];
            }
        }
        
        return targetNums[target];
    }
};