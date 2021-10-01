class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        while (left < right) {
            int mid = (left+right)/2;
            int curSum = 0;
            for (int num: nums) curSum += (num+mid-1)/mid;
            if (curSum > threshold) left = mid+1;
            else right = mid;
        }
        return left;
    }
};