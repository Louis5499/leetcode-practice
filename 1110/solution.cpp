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
    TreeNode* dfs(TreeNode* root, vector<TreeNode*> &output, unordered_set<int> &toDeleteSet, bool isRoot) {
        if (root == NULL) return NULL;

        bool shouldDelete = toDeleteSet.count(root->val);
        if (isRoot && !shouldDelete) output.push_back(root);
        root->left = dfs(root->left, output, toDeleteSet, shouldDelete);
        root->right = dfs(root->right, output, toDeleteSet, shouldDelete);
        return shouldDelete ? NULL : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> output;
        dfs(root, output, toDeleteSet, true);
        
        return output;
    }
    
};