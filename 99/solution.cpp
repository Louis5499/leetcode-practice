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
    TreeNode *firstElement = NULL, *secondElement = NULL, *prevElement = new TreeNode(INT_MIN);
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        
        int tmp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = tmp;
    }
    
    void dfs(TreeNode* node) {
        if (node == NULL) return;

        dfs(node->left);
        
        if (firstElement == NULL && prevElement->val > node->val) {
            firstElement = prevElement;
        }
        
        if (firstElement != NULL && prevElement->val > node->val) {
            secondElement = node;
        }
        prevElement = node;
        
        dfs(node->right);
    }
};