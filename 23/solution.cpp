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
private:
    ListNode* combineList(ListNode* listA, ListNode* listB) {
        if (listA == NULL) return listB;
        if (listB == NULL) return listA;
        
        if (listA->val < listB->val) {         
            listA->next = combineList(listA->next, listB);
            return listA;
        } else {
            listB->next = combineList(listB->next, listA);
            return listB;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int listLen = lists.size();
        
        for (int i=1; i<=listLen; i<<=1) {
            // i = 1, 2, 4, 8, 16 ...
            for (int j=0; j+i < listLen; j+=i*2) {
                lists[j] = combineList(lists[j], lists[j+i]);
            }
        }
        return lists[0];
    }
};