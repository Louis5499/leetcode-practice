class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long sum = 0, gain = 0;
        set<int> allNums(begin(nums1), end(nums1));
        for (int i=0; i<nums1.size(); i++) {
            long diff = abs(nums1[i] - nums2[i]);
            sum += diff;
            if (gain < diff) {
                // Utilize Binary Search
                auto candidate = allNums.lower_bound(nums2[i]);

                if (candidate != end(allNums)) {
                    gain = max(gain, diff - abs(*candidate - nums2[i]));
                }
                
                if (candidate != begin(allNums)) {
                    gain = max(gain, diff - abs(*prev(candidate) - nums2[i]));
                }
                
            }
        }
        return (sum - gain)%1000000007;
    }
};