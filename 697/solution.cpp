class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> counts, first;
        int maxDegree = 0, res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (first.count(nums[i]) == 0) first[nums[i]] = i;
            if (++counts[nums[i]] > maxDegree) {
                maxDegree = counts[nums[i]];
                res = i-first[nums[i]] + 1;
            } else if (counts[nums[i]] == maxDegree) {
                res = min(res, i-first[nums[i]] + 1);
            }
        }
        return res;
    }
};