/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        Node *curNode = head;
        while (curNode != NULL) {
            Node *originalNext = curNode->next;
            curNode->next = new Node(curNode->val);
            curNode->next->next = originalNext;
            curNode = originalNext;
        }
        
        curNode = head;
        while (curNode != NULL) {
            Node* rndInOriginalList = curNode->random;
            if (rndInOriginalList != NULL) curNode->next->random = rndInOriginalList->next;
            curNode = curNode->next->next;
        }
        
        Node *newList = head->next, *newHead = head->next;
        while (newList != NULL) {
            head->next = head->next != NULL ? head->next->next : NULL;
            newList->next = newList->next != NULL ? newList->next->next : NULL;
            head = head->next;
            newList = newList->next;
        }
        
        return newHead;
    }
};