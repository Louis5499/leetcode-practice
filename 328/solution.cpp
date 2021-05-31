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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* oddHead = head, *evenHead = head->next, *memorizeEvenHead = evenHead;
        while (evenHead != NULL && evenHead->next != NULL) {
            oddHead->next = oddHead->next->next;
            evenHead->next = evenHead->next->next;
            oddHead = oddHead->next;
            evenHead = evenHead->next;
        }
        oddHead->next = memorizeEvenHead;
        return head;
    }
};