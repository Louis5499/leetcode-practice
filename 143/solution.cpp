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
    void reorderList(ListNode* head) {
        ListNode *prev = NULL, *node = head;
        int count = 0;
        while(node != NULL) {
            ListNode *originalNext = node->next;
            ListNode *newNode = new ListNode(node->val);
            newNode->next = prev;
            prev = newNode;
            node = originalNext;
            count++;
        }
        
        ListNode *newSeq = new ListNode(-1), *newSeqHead = newSeq;
        for (int i=0;i<count;i++) {
            if (i&1) {
                newSeq->next = prev;
                prev = prev->next;
            } else {                
                newSeq->next = head;
                head = head->next;
            }
            newSeq = newSeq->next;
        }
        newSeq->next = NULL;
        head = newSeqHead->next;
    }
};