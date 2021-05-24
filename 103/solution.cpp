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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> output;
        if (root == NULL) return output;

        q.push(root);
        bool leftFirst = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> subput(size, 0);

            for (int i=0; i<size; i++) {
                TreeNode *node = q.front();

                int idx = leftFirst ? i : size - 1 - i;
                subput[idx] = node->val;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                q.pop();
            }
            leftFirst = !leftFirst;
            output.emplace_back(subput);
        }
        return output;
    }
};