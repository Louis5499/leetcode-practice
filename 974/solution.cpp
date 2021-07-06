class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k, 0);
        counts[0] = 1;
        int sum = 0, ans = 0;
        for (auto num: nums) {
            sum = (sum+num)%k;
            if (sum < 0) sum += k;
            ans += counts[sum];
            counts[sum] += 1;
        }
        return ans;
    }
};