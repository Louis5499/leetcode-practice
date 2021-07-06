class Solution {
private:
    int delta[5] = {0, 1, 0, -1, 0};
    int m, n;
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &total, int &mindist, int walk, int oi, int oj) {
        mindist = -1;
        auto dist = grid;
        queue<pair<int, int>> q;
        q.emplace(oi, oj);
        while (q.size()) {
            auto ij = q.front();
            q.pop();
            for (int d=0; d<4; ++d) {
                int i = ij.first + delta[d];
                int j = ij.second + delta[d+1];
                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == walk) {
                    grid[i][j]--;
                    dist[i][j] = dist[ij.first][ij.second] + 1;
                    total[i][j] += dist[i][j] - 1;
                    q.emplace(i, j);
                    if (mindist < 0 || mindist > total[i][j])
                        mindist = total[i][j];
                }
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>> grid) {
        m = grid.size(), n = grid[0].size();
        auto total = grid;
        int walk = 0, mindist;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == 1) {
                    bfs(grid, total, mindist, walk, i, j);
                    walk--;
                }
            }
        }
        return mindist;
    }
};