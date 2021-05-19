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
    int maxDepth(TreeNode* root) {
        return findDepth(root, 0);   
    }
    
    int findDepth(TreeNode* root, int layer) {
        if (root == NULL) return layer;
        return max(findDepth(root->right, layer+1), findDepth(root->left, layer+1));   
    }
};