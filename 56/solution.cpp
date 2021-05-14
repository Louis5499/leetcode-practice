class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;
        int n = intervals.size();
        int i=0, j=0;
        while(i<n) {
            j = i+1;
            while(j < n && intervals[i][1] >= intervals[j][0]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                j++;
            }
            output.emplace_back(intervals[i]);
            i = j;
        }
        return output;
    }
};