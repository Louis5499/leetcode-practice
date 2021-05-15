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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *output = new ListNode(-1), *outputHead = output;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                output->next = l1;
                l1 = l1->next;
            } else {
                output->next = l2;
                l2 = l2->next;
            }
            
            output = output->next;
        }
        
        output->next = l1 != NULL ? l1 : l2;
        
        return outputHead->next;
    }
};