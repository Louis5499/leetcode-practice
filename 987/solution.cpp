/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> colMap;
        dfs(colMap, root, 0, 0);
        
        vector<vector<int>> result;
        for (auto it: colMap) {
            vector<int> perCol;
            for (auto element: it.second) {
                perCol.insert(perCol.end(), element.second.begin(), element.second.end());
            }
            result.emplace_back(perCol);
        } 
        return result;
    }
    
    void dfs(map<int, map<int, multiset<int>>> &colMap, TreeNode* root, int row, int col) {
        colMap[col][row].insert(root->val);
        if (root->left) dfs(colMap, root->left, row+1, col-1);
        if (root->right) dfs(colMap, root->right, row+1, col+1);
    }
};