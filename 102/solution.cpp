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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalList;
        queue<TreeNode*> q;
        
        if (root == NULL) return finalList;
        q.push(root);
        
        while(!q.empty()) {
            int numInLayer = q.size();
            vector<int> subList(numInLayer, 0);
            for (int i=0; i<numInLayer; i++) {
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                subList[i] = q.front()->val;
                q.pop();
            }
            finalList.emplace_back(subList);
        }
        
        return finalList;
    }
};