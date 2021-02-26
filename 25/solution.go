/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	node := head
	for i := 1; i < k && node != nil; i++ {
		node = node.Next
	}

	if node == nil {
		return head
	}
	return reverseSeq(head, reverseKGroup(node.Next, k), k)
}

func reverseSeq(head *ListNode, lastNode *ListNode, k int) *ListNode {
	nextPtr := head.Next
	head.Next = lastNode
	if k == 1 {
		return head
	}
	return reverseSeq(nextPtr, head, k-1)
}