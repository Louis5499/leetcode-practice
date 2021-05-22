class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> compensate;
        int count = 0;
        for (int n1: nums1) {
            for (int n2: nums2) {
                compensate[n1+n2]++;
            }
        }
        
        for (int n3: nums3) {
            for (int n4: nums4) {
                auto found = compensate.find(-(n3+n4));
                if (found != compensate.end()) count+=found->second;
            }
        }
        return count;
    }
};