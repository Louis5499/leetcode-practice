class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % k != 0 || k < 0) return false;
        unordered_set<int> visited;
        return canPart(visited, nums, k, 0, 0, sum/k);
    }
    
    bool canPart(unordered_set<int> &visited, vector<int>& nums, int k, int si, int curSum, int target) {
        if (k == 0) return true;
        if (curSum == target) return canPart(visited, nums, k-1, 0, 0, target);
        for(int i=si; i<nums.size(); i++) {
            if (!visited.count(i)) {
                visited.insert(i);
                if(canPart(visited, nums, k, i+1, curSum+nums[i], target)) return true;
                visited.erase(i);
            }
        }
        return false;
    }
};