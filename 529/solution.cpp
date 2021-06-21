class Solution {
public:
    vector<vector<int>> v = { {1,-1},{ 1,0 },{ 1,1 },{ -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 } };
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        process(board, click);
        return board;
    }
    
    bool isInBounadary(vector<vector<char>>& board, int i, int j) {
        return (i >= 0 && i < board.size() && j >= 0 && j < board[0].size());
    }
    
    void process(vector<vector<char>>& board, vector<int>& click) {
        if (!isInBounadary(board, click[0], click[1])) return;
        int count = 0;
        if (board[click[0]][click[1]] == 'E') {
            for (auto &dir: v) {
                int x = click[0] + dir[0];
                int y = click[1] + dir[1];
                if (isInBounadary(board, x, y) && board[x][y] == 'M') count++;
            }

            if (count > 0) {
                board[click[0]][click[1]] = '0' + count;
            } else {
                board[click[0]][click[1]] = 'B';
                for (auto &dir: v) {
                    click[0] += dir[0];
                    click[1] += dir[1];
                    process(board, click);
                    click[0] -= dir[0];
                    click[1] -= dir[1];
                }
            }
        }
    }
};