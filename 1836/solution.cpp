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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> m;
        ListNode *cur = head;
        while (cur != NULL) {
            m[cur->val]++;
            cur = cur->next;
        }
        
        ListNode *mockHead = new ListNode(-1, head);
        ListNode *prev = mockHead;
        cur = head;
        while (cur != NULL) {
            while (cur != NULL && m[cur->val] > 1) {
                cur = cur->next;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur == NULL ? NULL : cur->next;
        }
        
        return mockHead->next;
    }
};