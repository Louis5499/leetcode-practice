class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        vector<int> result;
        for (int i: nums1) m[i]++;
        for (int num: nums2) {
            if (m[num]-- > 0) result.emplace_back(num);
        }
        return result;
    }
};