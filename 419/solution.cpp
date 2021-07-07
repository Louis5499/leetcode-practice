class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'X') {
                    dfs(board, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
        if (board[i][j] != 'X') return;
        board[i][j] = '.';
        if (i >= 1)  dfs(board, i-1, j, m, n);
        if (j >= 1)  dfs(board, i, j-1, m, n);
        if (i < m-1) dfs(board, i+1, j, m, n);
        if (j < n-1) dfs(board, i, j+1, m, n);
    }
};