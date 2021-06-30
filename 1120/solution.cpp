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
    double maxVal = 0.0;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return maxVal;
    }
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> cell{1, root->val}, left, right;
        if (root->left) left = dfs(root->left);
        if (root->right) right = dfs(root->right);
        cell.first += left.first + right.first;
        cell.second += left.second + right.second;
        double div = (double)cell.second/(double)cell.first;
        if (div > maxVal) maxVal = div;
        return cell;
    }
};