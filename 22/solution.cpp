class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> pool;
        generateParent(0, 0, "", pool, n);
        return pool;
    }

    void generateParent(int l, int r, string res, vector<string> &pool, int n) {
        if (l < n) generateParent(l+1, r, res + '(', pool, n);
        if (l>r && r < n) generateParent(l, r+1, res + ')', pool, n);
        
        if (l==n && r==n) pool.emplace_back(res);
    }
};