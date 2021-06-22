class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0, r=arr.size(), m;
        while (l<r) {
            m = (l+r)/2;
            if (arr[m] - m - 1 < k) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return l + k;
    }
};