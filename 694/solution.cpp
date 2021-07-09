class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> pool;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]) {
                    string s = "";
                    dfs(grid, i, j, s, "o");
                    pool.insert(s);
                }
            }
        }
        return pool.size();
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, string &s, string dir) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0) return;
        s += dir;
        grid[i][j] = 0;
        dfs(grid, i-1, j, s, "u");
        dfs(grid, i+1, j, s, "d");
        dfs(grid, i, j-1, s, "l");
        dfs(grid, i, j+1, s, "r");
        s += 'b';
    }
};