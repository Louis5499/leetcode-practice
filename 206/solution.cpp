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
    ListNode* reverseList(ListNode* head) {
        ListNode *lastNode = NULL, *nextNode;
        while (head != NULL) {
            nextNode = head->next;
            head->next = lastNode;
            lastNode = head;
            head = nextNode;
        }
        return lastNode;
    }
};