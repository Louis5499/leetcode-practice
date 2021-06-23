class Solution {
public:
    int get(int i, int j, vector<vector<int>>& g) {
      return (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
    }
    
    int paint(int i, int j, int clr, vector<vector<int>>& g) {
        if (get(i, j, g) != 1) return 0;
        g[i][j] = clr;
        return 1 + paint(i+1, j, clr, g) + paint(i-1, j, clr, g) + paint(i, j+1, clr, g) + paint(i, j-1, clr, g);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> color = { 0, 0 };
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) color.push_back(paint(i, j, color.size(), grid));
            }
        }
        
        int res = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> dirs = { get(i+1, j, grid), get(i-1, j, grid), get(i, j+1, grid), get(i, j-1, grid) };
                    res = max(res, 1 + accumulate(dirs.begin(), dirs.end(), 0, [&](int a, int b) { return a + color[b]; }));
                }
            }
        }
        return res == 0 ? grid.size()*grid[0].size() : res;
    }
};