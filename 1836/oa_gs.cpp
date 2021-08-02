
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
        unordered_set<int> pool;
        ListNode *mockHead = new ListNode(-1, head);
        ListNode *prev = mockHead, *now = head;
        while (now != NULL) {
            while (now != NULL && pool.count(now->val)) {
                now = now == NULL ? NULL : now->next;
            }
            prev->next = now;
            if (now != NULL) {
                pool.insert(now->val);    
            }
            prev = prev->next;
            now = now == NULL ? NULL : now->next;
        }
        
        return mockHead->next;
    }
};