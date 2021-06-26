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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* prev = dummyHead, *node = head, *next = head->next;
        
        while (node != NULL && next != NULL) {
            ListNode *tmp = next->next;
            prev->next = next;
            next->next = node;
            node->next = tmp;

            prev = prev->next->next;
            node = prev->next ? prev->next : NULL;
            next = prev->next && prev->next->next ? prev->next->next : NULL;
        }
        
        return dummyHead->next;
    }
};