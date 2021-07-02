class Solution {
public:
    int count = 0;
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
    
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start == end) return;
        
        int mid = (start+end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        checkCount(nums, start, mid, end);
    }
    
    void checkCount(vector<int>& nums, int start, int mid, int end) {
        int l = start, r = mid+1;
        while (l <= mid && r <= end) {
            if ((long)nums[l] > (long)2*nums[r]) {
                count += (mid-l+1);
                r++;
            } else {
                l++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
    }
};