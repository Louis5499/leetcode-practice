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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return result.second;
    }
    
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return { 0, 0 };
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int maxInOneBranch = max(left.first, right.first) + 1;
        int maxPath = max(left.first + right.first, max(left.second, right.second));
        return pair<int, int>{maxInOneBranch, maxPath};
    }
};