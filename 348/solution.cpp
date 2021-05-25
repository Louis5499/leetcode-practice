class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int antiDiagonal;
    int totalLen;

    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.assign(n, 0);
        cols.assign(n, 0);
        diagonal = 0;
        antiDiagonal = 0;
        totalLen = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int curPlayer = player == 1 ? -1 : 1;
        rows[row] += curPlayer;
        cols[col] += curPlayer;
        if (row == col) diagonal += curPlayer;
        if (row == totalLen-col-1) antiDiagonal += curPlayer;
        
        if (abs(rows[row]) == totalLen ||
            abs(cols[col]) == totalLen ||
            abs(diagonal) == totalLen ||
            abs(antiDiagonal) == totalLen) {
            return player;
        } else {
            return 0;
        }
            
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */