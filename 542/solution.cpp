class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int farestDist = m+n;
        
        vector<vector<int>> dst(m, vector<int>(n, farestDist));
        queue<pair<int, int>> pendingQueue;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    dst[i][j] = 0;
                    pendingQueue.push(make_pair(i, j));
                }
                else dst[i][j] = farestDist;
            }
        }
        
        // up, down, left, right
        int dirs[4][2] = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 }
        };
        
        while (!pendingQueue.empty()) {
            pair<int, int> axis = pendingQueue.front();
            pendingQueue.pop();

            for (auto dir: dirs) {
                int xAxis = axis.first + dir[0];
                int yAxis = axis.second + dir[1];
                
                if (xAxis >= 0 && xAxis < m && yAxis >= 0 && yAxis < n) {
                    if (dst[xAxis][yAxis] == farestDist) pendingQueue.push(make_pair(xAxis, yAxis));
                    dst[xAxis][yAxis] = min(dst[xAxis][yAxis], dst[axis.first][axis.second] + 1);
                }
            }
        }
        
        return dst;
    }
};