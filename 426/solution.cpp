/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = new Node(-1), *cur = NULL, *prev = head;
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) return NULL;
        dfs(root);
        head = head->right;
        head->left = cur;
        cur->right = head;
        return head;
    }
    
    void dfs(Node* root) {
        if (root->left) dfs(root->left);
        cur = root;
        prev->right = cur;
        cur->left = prev;
        prev = cur;
        if (root->right) dfs(root->right);
    }
};