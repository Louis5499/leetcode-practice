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
    int goodNodes(TreeNode* root) {
        return findGood(root, root->val);
    }
    int findGood(TreeNode *root, int maxVal) {
        if (root == NULL) return 0;
        int count = 0;
        if (root->val >= maxVal) count++;
        return findGood(root->left, max(root->val, maxVal)) + findGood(root->right, max(root->val, maxVal)) + count;
    }
};