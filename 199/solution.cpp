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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> output;
        if (root == NULL) return output;
        while(!q.empty()) {
            int n = q.size();
            TreeNode *node = q.front();
            output.emplace_back(node->val);
            while (n--) {
                node = q.front();
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
                q.pop();
            }
        }
        return output;
    }
    
};