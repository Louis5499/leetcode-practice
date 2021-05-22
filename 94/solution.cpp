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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderSeq;
        if (root == NULL) return inorderSeq;
        inorderRun(root, inorderSeq);
        return inorderSeq;
    }
    
    void inorderRun(TreeNode* root, vector<int> &inorderSeq) {
        if (root->left != NULL) inorderRun(root->left, inorderSeq);
        inorderSeq.emplace_back(root->val);
        if (root->right != NULL) inorderRun(root->right, inorderSeq);
    }
};