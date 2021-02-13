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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *firstItem = dummy;

        int remainingSum = 0;
        
        while(l1 != NULL || l2 != NULL) {
            int sum = remainingSum;
            if (l1 != NULL) sum += l1->val;
            if (l2 != NULL) sum += l2->val;
            remainingSum = sum/10;
            dummy->val = sum%10;
            
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            
            if (l1 == NULL && l2 == NULL) {
                dummy->next = NULL;
            } else {
                dummy->next = new ListNode(0);
                dummy = dummy->next;
            }
        }
        
        if (remainingSum > 0) {
            dummy->next = new ListNode(remainingSum);
        }

        return firstItem;
    }
};