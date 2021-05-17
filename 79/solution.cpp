class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (searching(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool searching(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (idx == word.length()) return true;
        if (i<0 || i>=n || j<0 || j>=m) return false;
        if (board[i][j] != word[idx]) return false;
        board[i][j] ^= 128;
        bool correct = searching(board, word, i+1, j, idx+1) || searching(board, word, i-1, j, idx+1) || searching(board, word, i, j+1, idx+1) || searching(board, word, i, j-1, idx+1);
        board[i][j] ^= 128;
        return correct;
    }
};