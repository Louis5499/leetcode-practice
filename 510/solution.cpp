/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right == NULL) {
            Node *cand = node->parent;
            while (cand != NULL && cand->val < node->val) cand = cand->parent;
            return cand;
        } else {
            Node *cand = node->right;
            while (cand->left != NULL) {
                cand = cand->left;
            }
            return cand;
        }
    }
};