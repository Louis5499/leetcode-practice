class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size()-1][matrix[0].size()-1]+1;
        while (lo < hi) {
            int mid = (hi-lo)/2 + lo;
            int count = 0, j = matrix[0].size()-1;
            for (int i=0; i<matrix.size(); i++) {
                while (j >= 0 && matrix[i][j] > mid) j--;
                count += (j+1);
            }
            if (count < k) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};