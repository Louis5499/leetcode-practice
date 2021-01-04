// Select the top k element after using Quick Sort to sort the array.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sorting(nums, 0, nums.size()-1);
        return nums[nums.size() - k];
    }
    
    int partition(vector<int>& nums, int frontIdx, int backIdx) {
        int pivot = nums[backIdx];
        int storeIdx = frontIdx - 1;
        for (int currentIdx=frontIdx; currentIdx < backIdx; currentIdx++) {
            if (nums[currentIdx] < pivot) {
                storeIdx++;
                swap(nums, storeIdx, currentIdx);
            }
        }
        swap(nums, ++storeIdx, backIdx);
        return storeIdx;
    }
    
    void sorting(vector<int>& nums, int frontIdx, int backIdx) {
        if (frontIdx < backIdx) {
            int pivotIdx = partition(nums, frontIdx, backIdx);
            sorting(nums, frontIdx, pivotIdx-1);
            sorting(nums, pivotIdx + 1, backIdx);
        }
    }
    
    void swap(vector<int>& nums, int frontIdx, int backIdx) {
        int tmp = nums[frontIdx];
        nums[frontIdx] = nums[backIdx];
        nums[backIdx] = tmp;
    } 
};