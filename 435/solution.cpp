/**
 * The solution will run slower than we think, since we use our custom "mycompare" comparator.
 * However, in the viewpoint of complexity, we still reach O(nlogn) runtime, which is the optimal solution.
 * 
 * 
 **/
class Solution {
private:
    static bool mycompare(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycompare);
        
        int notOverlappedCount = 1;
        int n = intervals.size();
        int end = intervals[0][1];
        for (int i=1; i<n; i++) {
            if (end <= intervals[i][0]) {
                end = intervals[i][1];
                notOverlappedCount++;
            }
        }
        return n - notOverlappedCount;
    }
};