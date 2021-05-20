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
    bool validate(TreeNode *root, TreeNode *lowRoot, TreeNode *highRoot) {
        if (root == NULL) return true;
        if ((lowRoot != NULL && root->val <= lowRoot->val) || (highRoot != NULL && root->val >= highRoot->val)) {
            return false;
        }
        
        return validate(root->left, lowRoot, root) && validate(root->right, root, highRoot);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
};