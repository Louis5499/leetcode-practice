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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *a = p,  *b = q;
        while (a != b) {
            a = a == NULL ? q : a->parent;
            b = b == NULL ? p : b->parent;
        }
        return a;
    }
};