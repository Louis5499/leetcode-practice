/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (head == NULL) {
            head = node;
            head->next = head;
            return head;
        }
        
        Node *prev = head, *next = head->next;
        bool hasInserted = false;
        while (true) {
            if ((prev->val <= insertVal && insertVal <= next->val) ||
                (prev->val > next->val  && insertVal > prev->val) ||
                (prev->val > next->val  && insertVal < next->val)) {
                
                prev->next = node;
                node->next = next;
                hasInserted = true;
                break;
            }
            
            prev = prev->next;
            next = next->next;
            if (prev == head) break;
        }
        
        if (!hasInserted) {
            prev->next = node;
            node->next = next;
        }
        
        return head;
    }
};