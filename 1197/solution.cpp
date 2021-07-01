class Solution {
public:
    int hash(int x, int y) {
       return 3000 * x + y;
    }
    int dirs[8][2] = { {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2} };
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({0, 0});
        visited.insert(hash(x, y));
        if (x == 0 && y == 0) return 0;
        int steps = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                pair<int, int> cur = q.front(); q.pop();
                for (auto &dir: dirs) {
                    int mx = cur.first + dir[0];
                    int my = cur.second + dir[1];
                    if (mx == x && my == y) return steps;
                    if (mx >= -1 && my >= -1 && visited.count(hash(mx, my)) == 0) {
                        q.push({mx, my});
                        visited.insert(hash(mx, my));
                    }
                }        
            }
            steps++;
        }
        return -1;
    }
};