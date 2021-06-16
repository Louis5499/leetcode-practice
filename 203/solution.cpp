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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *node = new ListNode(-1), *newHead = node;
        node->next = head;
        while (node != NULL && node->next != NULL) {
            ListNode *cur = node;
            node = node->next;
            while (node != NULL && node->val == val) {
                node = node->next;
            }
            cur->next = node;
        }
        return newHead->next;
    }
};