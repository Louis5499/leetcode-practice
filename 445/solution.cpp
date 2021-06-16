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
        stack<int> l1Stk, l2Stk;
        
        while (l1 != NULL) {
            l1Stk.push(l1->val);
            l1 = l1->next;
        }
        
        while (l2 != NULL) {
            l2Stk.push(l2->val);
            l2 = l2->next;
        }
        
        int sum = 0;
        ListNode *node = new ListNode(0);
        while (!l1Stk.empty() || !l2Stk.empty()) {
            if (!l1Stk.empty()) {
                sum += l1Stk.top();
                l1Stk.pop();
            }
            
            if (!l2Stk.empty()) {
                sum += l2Stk.top();
                l2Stk.pop();
            }
            
            node->val = sum%10;
            ListNode *prev = new ListNode(sum/10);
            prev->next = node;
            node = prev;
            sum/=10;
        }
        return node->val == 0 ? node->next : node;
    }
};