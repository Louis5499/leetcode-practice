/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *node = head;
        stack<Node*> stk;
        while (node) {
            if (node->child) {
                if (node->next) stk.push(node->next);
                node->next = node->child;
                node->next->prev = node;
                node->child = NULL;
            }
            
            if (node->next == NULL && !stk.empty()) {
                node->next = stk.top(); stk.pop();
                node->next->prev = node;
            }
            
            node = node->next;
        }
        
        return head;
    }
};