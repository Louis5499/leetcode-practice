class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> pre(m, 0);
        vector<int> cur(m, 0);
        for (int i = 0; i < m; i++) {
            if (!obstacleGrid[i][0])
                pre[i] = 1;
            else break;
        }
        
        for (int j=1; j<n; j++) {
            bool flag = false;
            if (!obstacleGrid[0][j]) {
                cur[0] = pre[0];
                if (cur[0]) flag = true;
            } else cur[0] = 0;
            for (int i = 1; i < m; i++) {
                if (!obstacleGrid[i][j]) {
                    cur[i] = cur[i - 1] + pre[i];
                    if (cur[i]) flag = true;
                }
                else cur[i] = 0;
            }
            if (!flag) return 0;
            swap(pre, cur);
        }
        return pre[m-1];
    }
};