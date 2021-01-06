class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // Why right always "-1" ? Since the last element in vector would represent pivot point, according to partition function.
        return quickSort(points, 0, points.size() - 1, K-1);
    }
    
    vector<vector<int>> quickSort(vector<vector<int>>& points, int left, int right, int targetIdx) {
        while(true) {
            int pivotIdx = partition(points, left, right);
            
            if (pivotIdx == targetIdx) {
                vector<vector<int>> subVec(&points[0], &points[targetIdx + 1]);
                return subVec;
            }
            else if (pivotIdx < targetIdx) {
                left = pivotIdx + 1;
            }
            else {
                right = pivotIdx - 1;
            }
        }
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        int rnd = rand()%(right-left+1) + left;
        vector<int> pivot = points[rnd];
        swap(points[right], points[rnd]);
        
        int storeIdx = left;
        for (int i=left; i<right; i++) {
            if (comparingPoints(pivot, points[i])) {
                swap(points[i], points[storeIdx++]);
            }
        }
        
        swap(points[storeIdx], points[right]);
        return storeIdx;
    }
    
    bool comparingPoints(vector<int>& pointA, vector<int>& pointB) {
        return (pow(pointA[0], 2) + pow(pointA[1], 2)) > (pow(pointB[0], 2) + pow(pointB[1], 2));
    }    
};