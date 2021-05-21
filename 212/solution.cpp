class TrieNode {
    public:
        TrieNode **childrens;
        string word;
        TrieNode() {
            childrens = new TrieNode*[26]();
            word = "";
        }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode *root = new TrieNode();
        buildTrie(words, root);
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                dfs(board, root, i, j, ans);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, TrieNode *node, int i, int j, vector<string> &ans) {
        char c = board[i][j];
        if (c == '#' || node->childrens[c-'a'] == NULL) return;
        node = node->childrens[c-'a'];
        if (node->word != "") {
            ans.emplace_back(node->word);
            node->word = "";
        }
        
        board[i][j] = '#';
        if (i > 0) dfs(board, node, i-1, j, ans);
        if (i < board.size()-1) dfs(board, node, i+1, j, ans);
        if (j > 0) dfs(board, node, i, j-1, ans);
        if (j < board[0].size()-1) dfs(board, node, i, j+1, ans);
        board[i][j] = c;
    }
    
    void buildTrie(vector<string>& words, TrieNode *root) {
        for (string word: words) {
            TrieNode *node = root;
            for (char c: word) {
                int alpha = c-'a';
                if (node->childrens[alpha] == NULL) node->childrens[alpha] = new TrieNode();
                node = node->childrens[alpha];
            }
            node->word = word;
        }
    }
};