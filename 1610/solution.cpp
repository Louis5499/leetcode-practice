#define PI 3.14159265
#define MARGIN 1e-9

class Solution {
public:
    double getAngle(int xDiff, int yDiff) {
        return atan2(yDiff, xDiff)*180/PI;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int i, j, n = points.size(), common = 0;
        vector<double> vals;
        for (i=0; i<n; i++) {
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            if (x == 0 && y == 0) {
                common++;
            } else {
                double A = getAngle(x, y);
                // if (A < 0) A += 360;
                vals.emplace_back(A);
            }
        }
        
        sort(vals.begin(), vals.end());
        vector<double> ans = vals;
        ans.insert(ans.end(), vals.begin(), vals.end());
        for (i=vals.size(); i<ans.size(); i++) {
            ans[i] += 360;
        }
        int ret = 0;
        for (i=0, j=0; i<ans.size(); i++) {
            while (j<ans.size() && ans[j]-ans[i] <= angle+MARGIN) j++;
            ret = max(ret, j-i);
        }
        return ret + common;
    }
};