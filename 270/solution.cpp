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
    int closestValue(TreeNode* root, double target) {
        if (target < root->val && root->left) {
            int found = closestValue(root->left, target);
            if (abs(target - found) < abs(target - root->val)) return found;
            else return root->val;
        }
        else if (target > root->val && root->right) {
            int found = closestValue(root->right, target);
            if (abs(target - found) < abs(target - root->val)) return found;
            else return root->val;
        }
        else {
            return root->val;
        }
    }
};