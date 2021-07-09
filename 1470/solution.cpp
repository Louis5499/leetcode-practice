class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr(2*n, 0);
        int x = 0;
        for (int i=0; i<n; i++) {
            arr[x++] = nums[i];
            arr[x++] = nums[i+n];
        }
        return arr;
    }
};