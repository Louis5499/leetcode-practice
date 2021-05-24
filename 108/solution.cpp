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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        return buildTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& nums, int i, int j) {
        if (i>j) return NULL;
        int mid = (i+j)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, i, mid-1);
        node->right = buildTree(nums, mid+1, j);
        return node;
    }
};