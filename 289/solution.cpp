class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int count = -board[i][j];
                for (int sI=max(0, i-1); sI<min(n, i+2); sI++) {
                    for (int sJ=max(0, j-1); sJ<min(m, j+2); sJ++) {
                        if (board[sI][sJ]&1) count++;
                    }
                }
                if ((count|board[i][j]) == 3) board[i][j] |= 2;
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};