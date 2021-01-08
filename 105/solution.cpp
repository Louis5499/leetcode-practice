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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderTable;
        
        for (int i=0; i<inorder.size(); i++) {
            inorderTable[inorder[i]] = i;
        }
        return solve(preorder, 0, inorder, 0, inorder.size(), inorderTable);
    }
    
private:
    TreeNode* solve(vector<int>& preorder, int pivot, vector<int>& inorder, int inI, int inJ, unordered_map<int, int>& inorderTable) {
        if (pivot >= preorder.size() || inI >= inJ) return NULL;
        int midElement = preorder[pivot];
        
        int found = inorderTable[midElement];
        int distance = found - inI;
            
        TreeNode *treeNode = new TreeNode(midElement);
        treeNode->left = solve(preorder, pivot+1, inorder, inI, inI + distance, inorderTable);
        treeNode->right = solve(preorder, pivot+distance+1, inorder, inI + distance + 1, inJ, inorderTable);
        return treeNode;
    }
};