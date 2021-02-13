/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummy := new(ListNode)
	firstItem := dummy
	carry := 0

	for l1 != nil || l2 != nil {
		sum := carry
		if l1 != nil {
			sum += l1.Val
		}
		if l2 != nil {
			sum += l2.Val
		}
		carry = sum / 10
		dummy.Val = sum % 10

		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}

		if l1 == nil && l2 == nil {
			dummy.Next = nil
		} else {
			dummy.Next = new(ListNode)
			dummy = dummy.Next
		}
	}

	if carry > 0 {
		dummy.Next = new(ListNode)
		dummy.Next.Val = carry
	}
	return firstItem
}