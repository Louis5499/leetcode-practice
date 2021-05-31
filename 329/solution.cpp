class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int count = 0;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                count = max(count, findLongest(matrix, i, j, cache));
            }
        }
        return count;
    }
    
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int findLongest(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&cache) {
        if (cache[i][j] != 0) return cache[i][j];
        for (auto dir: dirs) {
            int x = i+dir[0], y = j+dir[1];
            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[i][j] >= matrix[x][y]) continue;
            cache[i][j] = max(cache[i][j], findLongest(matrix, x, y, cache));
        }
        return ++cache[i][j];
    }
};