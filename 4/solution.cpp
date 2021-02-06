class Solution {
private:
    double findNMostVal(int *arr1, int *arr2, int arr1Len, int arr2Len, int k) {
        if(arr1Len == 0) return arr2[k-1];
        else if (arr2Len == 0) return arr1[k-1];
        else if (k == 1) return min(arr1[0], arr2[0]);
        else {
            int halfIdx = k/2;
            int arr1HalfIdx = min(halfIdx, arr1Len);
            int arr2HalfIdx = min(halfIdx, arr2Len);
            if (arr1[arr1HalfIdx - 1] > arr2[arr2HalfIdx - 1]) {
                return findNMostVal(arr1, arr2+arr2HalfIdx, arr1Len, arr2Len - arr2HalfIdx, k - arr2HalfIdx);
            } else {
                return findNMostVal(arr1+arr1HalfIdx, arr2, arr1Len - arr1HalfIdx, arr2Len, k - arr1HalfIdx);
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int *arr1 = nums1.data();
        int *arr2 = nums2.data();
        int arr1Len = nums1.size();
        int arr2Len = nums2.size();
        int totalLen = arr1Len + arr2Len;

        if (totalLen & 1) {
            // total length is odd => find the median num
            return findNMostVal(arr1, arr2, arr1Len, arr2Len, (arr1Len+arr2Len)/2 + 1);
        } else {
            // total length is even => find the avg val of two median nums
            return (findNMostVal(arr1, arr2, arr1Len, arr2Len, (arr1Len+arr2Len)/2) + findNMostVal(arr1, arr2, arr1Len, arr2Len, (arr1Len+arr2Len)/2 + 1))/2;
        }
    }
};