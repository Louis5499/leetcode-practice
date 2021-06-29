class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({start[0], start[1]});
        visited.insert({start[0], start[1]});
        while (!q.empty()) {
            pair<int, int> pos = q.front(); q.pop();
            for (auto &dir: dirs) {
                int i = pos.first;
                int j = pos.second;
                while (inBorder(maze, i, j) && maze[i][j] == 0) {
                    i += dir[0];
                    j += dir[1];
                }
                i -= dir[0], j -= dir[1];
                if (visited.count({i, j})) continue;
                visited.insert({i, j});
                if (destination[0] == i && destination[1] == j) return true;
                q.push({ i, j });
            }
        }
        return false;
    }
    
    int dirs[4][2] = { {1, 0}, {-1, 0}, {0 ,1}, {0, -1} };

    bool inBorder(vector<vector<int>>& maze, int i, int j) {
        return i >= 0 && i < maze.size() && j >= 0 && j < maze[0].size();
    }
};