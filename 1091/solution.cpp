class Solution {
public:
    int dirs[8][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} };
    bool isInBoundary(vector<vector<int>>& grid, int i, int j) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if (grid[0][0]) return -1;
        grid[0][0] = 1;
        q.push({0, 0});
        int step = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                pair<int, int> pos = q.front(); q.pop();
                if (pos.first == grid.size()-1 && pos.second == grid[0].size()-1) return step;
                for (int dir=0; dir<8; dir++) {
                    int x = dirs[dir][0] + pos.first;
                    int y = dirs[dir][1] + pos.second;
                    if(isInBoundary(grid, x, y) && grid[x][y] == 0) {
                        grid[x][y] = step+1;
                        q.push({x, y});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};