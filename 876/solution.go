/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func middleNode(head *ListNode) *ListNode {
	fast := head
	slow := head
	
	for fast.Next != nil && fast.Next.Next != nil {
			fast = fast.Next.Next
			slow = slow.Next
	}
	
	if fast.Next != nil {
			return slow.Next
	} else {
			return slow
	}
}