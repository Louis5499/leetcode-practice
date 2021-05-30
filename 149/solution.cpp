class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i=0; i<points.size(); i++) {
            int samePoint = 1;
            unordered_map<double, int> map;
            for (int j=i+1; j<points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    samePoint++;
                } else if (points[i][0] == points[j][0]) {
                    map[INT_MAX]++;
                } else {
                    double slope = (double) (points[j][1]-points[i][1])/(points[j][0]-points[i][0]);
                    map[slope]++;
                }
            }
            int localMax = 0;
            for (auto m: map) {
                localMax = max(localMax, m.second);
            }
            localMax += samePoint;
            result = max(localMax, result);
        }
        return result;
    }
};