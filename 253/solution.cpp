class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start(n, 0);
        vector<int> end(n, 0);
        
        for (int i=0; i<n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int rooms = 0, endIdx = 0;
        for (int i=0; i<n; i++) {
            if (start[i] < end[endIdx]) rooms++;
            else endIdx++; // Move new meeting (i) to just released room
        }
        return rooms;
    }
};