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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            result.emplace_back(root->val);
            dfs(root->left, result, true, false);
            dfs(root->right, result, false, true);
        }
        return result;
    }
    
    void dfs(TreeNode* node, vector<int> &result, bool lb, bool rb) {
        if (node == NULL) return;
        if (lb) result.emplace_back(node->val);
        if (!lb && !rb && !node->left && !node->right) result.emplace_back(node->val);
        dfs(node->left, result, lb, rb && !node->right);
        dfs(node->right, result, lb && !node->left, rb);
        if (rb) result.emplace_back(node->val);
    }
};