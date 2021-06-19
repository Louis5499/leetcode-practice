/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        
        int i=0, j=dim[1]-1, ans = -1;
        while (i < dim[0] && j >= 0) {
            if (binaryMatrix.get(i, j) == 0) {
                i++;
            } else {
                ans = j;
                j--;
            }
        }
        
        return ans;
    }
};