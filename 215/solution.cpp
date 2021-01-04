// Optimization method
// 1. Use Selection Sort not quick sort (Enhanced version of quick sort)
// 2. Don't choose last element as the pivot, "randonly choose"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size()-k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int targetIdx) {
        while (true) {
            int pivot = partition(nums, left, right);
            
            if (pivot == targetIdx) {
                return nums[pivot];
            } else if (pivot < targetIdx) {
                left = pivot+1;
            } else {
                right = pivot-1;
            }
        }
        return 0;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        
        // Randomized to find pivot value
        int pivotIdx = rand()%(right-left+1) + left;
        int pivot = nums[pivotIdx];
        
        // Movie pivot to last element, it's helpful when conducting the below logics.
        swap(nums[pivotIdx], nums[right]);
        
        // Put element less than pivot to correct place
        int storeIdx = left;
        for (int idx=left; idx < right; idx++) {
            if (nums[idx] < pivot) {
                swap(nums[storeIdx++], nums[idx]);
            }
        }
        
        // Move pivot back correct position.
        swap(nums[right], nums[storeIdx]);
        return storeIdx;
    }
};