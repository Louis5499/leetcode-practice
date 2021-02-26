/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *nextPtr = head;
        for (int i=1; i<k && nextPtr != NULL; i++) {
            nextPtr = nextPtr->next;
        }
        if (nextPtr == NULL) {
            return head;
        }
        return reverseSeq(head, reverseKGroup(nextPtr->next, k), k);
    }
    
    ListNode* reverseSeq(ListNode *head, ListNode *lastNode, int k) {
        ListNode *nextPtr = head->next;
        head->next = lastNode;
        if (k == 1) {
            return head;
        } 
        return reverseSeq(nextPtr, head, k-1);
    }
};