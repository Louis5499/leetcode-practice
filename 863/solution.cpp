/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> pos;
        vector<int> result;
        find(root, target, pos);
        dfs(root, target, pos[root], k, pos, result);
        return result;
    }
    
    int find(TreeNode* node, TreeNode* target, unordered_map<TreeNode*, int> &pos) {
        if (node == NULL) return -1;
        if (node == target) {
            pos[node] = 0;
            return 0;
        }
        
        int left = find(node->left, target, pos);
        if (left >= 0) {
            pos[node] = left+1;
            return left+1;
        }
        
        int right = find(node->right, target, pos);
        if (right >= 0) {
            pos[node] = right+1;
            return right+1;
        }
        
        return -1;
    }
    
    void dfs(TreeNode* node, TreeNode* target, int length, int k, unordered_map<TreeNode*, int> &pos, vector<int> &result) {
        if (node == NULL) return;
        if (pos.find(node) != pos.end()) length = pos[node];
        if (length == k) result.emplace_back(node->val);
        dfs(node->left, target, length+1, k, pos, result);
        dfs(node->right, target, length+1, k, pos, result);
        
    }
};