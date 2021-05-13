class Solution {
public:
    void BFS(vector<vector<bool>> &visited, queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        int R[4] = {0, -1, 0, 1};
        int C[4] = {-1, 0, 1, 0};
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int i = p.first, j = p.second;
            for(int k = 0; k < 4 ; k++) {
                int x = i + R[k], y = j + C[k];
                if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() 
                  && !visited[x][y] && grid[x][y]  >= grid[i][j]) {
                    visited[x][y] = true;
                    q.push({x,y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(!matrix.size()) return res;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vpac(n, vector<bool>(m));
        vector<vector<bool>> vatl(n, vector<bool>(m));
        queue<pair<int, int>> qpac;
        queue<pair<int, int>> qatl;
        for(int i = 0; i < n; i++) {
            vpac[i][0] = true;
            qpac.push({i,0});
            vatl[i][m-1] = true;
            qatl.push({i, m-1});
        }
        for(int j = 0; j < m; j++) {
            vpac[0][j] = true;
            qpac.push({0,j});
            vatl[n-1][j] = true;
            qatl.push({n-1, j});
        }
        BFS(vpac, qpac, matrix);
        BFS(vatl, qatl, matrix);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vpac[i][j] && vatl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
    
};