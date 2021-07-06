class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> pool(nums1.begin(), nums1.end());
        vector<int> output;
        for (auto num: nums2) {
            if (pool.count(num)) {
                output.emplace_back(num);
                pool.erase(num);
            }
        }
        return output;
    }
};