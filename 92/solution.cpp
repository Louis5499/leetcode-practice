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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *node = head, *dummyHead = new ListNode(-1), *prev = dummyHead;
        dummyHead->next = head;
        right = right - left;
        while (--left) {
            prev = prev->next;
        }
        node = prev->next;

        while (right--) {
            ListNode *tmp = prev->next;
            prev->next = node->next;
            node->next = node->next->next;
            prev->next->next = tmp;
        }
        return dummyHead->next;
    }
};