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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL) slow = slow->next;
        slow = reverse(slow);
        while (slow != NULL) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* node) {
        ListNode *preNode = NULL, *curNode = node;
        while (curNode != NULL) {
            ListNode *tmp = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = tmp;
        }
        return preNode;
    }
};