class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        // Border check
        for (int i=0; i<m; i++) {
            if (board[i][0] == 'O') traverse(board, i, 0);
            if (board[i][n-1] == 'O') traverse(board, i, n-1);
        }
        for (int j=0; j<n; j++) {
            if (board[0][j] == 'O') traverse(board, 0, j);
            if (board[m-1][j] == 'O') traverse(board, m-1, j);
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == '1') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
    }
    void traverse(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '1';
        if (i > 0 && board[i-1][j] == 'O') traverse(board, i-1, j);
        if (i < board.size()-1 && board[i+1][j] == 'O') traverse(board, i+1, j);
        if (j > 0 && board[i][j-1] == 'O') traverse(board, i, j-1);
        if (j < board[0].size()-1 && board[i][j+1] == 'O') traverse(board, i, j+1);
    }
};