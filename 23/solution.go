/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 func combineList(listA *ListNode, listB *ListNode) *ListNode {
	if listA == nil {
			return listB
	}
	if listB == nil {
			return listA
	}
	
	if listA.Val < listB.Val {
			listA.Next = combineList(listA.Next, listB)
			return listA
	} else {
			listB.Next = combineList(listB.Next, listA)
			return listB
	}
}

func mergeKLists(lists []*ListNode) *ListNode {
	listLen := len(lists)
	if listLen == 0 {
			return nil
	}
	
	
	for i := 1; i < listLen; i <<= 1 {
			// i = 1, 2, 4, 8, 16 ...
			for j := 0; i+j < listLen; j += i*2 {
					lists[j] = combineList(lists[j], lists[i+j])
			}
	}
	return lists[0]
}