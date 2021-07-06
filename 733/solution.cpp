class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        queue<pair<int, int>> q;
        int originalColor = image[sr][sc];
        q.push({sr, sc});
        while (!q.empty()) {
            pair<int, int> pos = q.front(); q.pop();
            image[pos.first][pos.second] = newColor;
            for (auto dir: dirs) {
                int nr = pos.first+dir[0];
                int nc = pos.second+dir[1];
                if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size()) {
                    if (image[nr][nc] == originalColor) {
                        q.push({nr, nc});
                    }
                }
            }
        }
        return image;
    }
};