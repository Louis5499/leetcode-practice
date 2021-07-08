class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]]++;
        }
        
        return starters.size();
    }
};