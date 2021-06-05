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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode *first = q.front(); q.pop();
            TreeNode *second = q.front(); q.pop();
            if (first == NULL && second == NULL) continue;
            else if (first == NULL || second == NULL) return false;
            else if (first->val != second->val) return false;
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
        return true;
    }
};