class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const size_t arrayLen = nums.size();
        map<int, int> complementElement;
        
        for (int idx=0; idx < arrayLen; idx++) {
            int complementNum = target - nums[idx];
            if (complementElement.find(complementNum) != complementElement.end()) {
                map<int, int>::iterator ele = complementElement.find(complementNum);
                return {ele->second, idx};
            }
            complementElement[nums[idx]] = idx;
        }
        return vector<int>();
    }
};