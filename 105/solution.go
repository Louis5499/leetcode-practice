// In Go, we don't need to do index passing like C, it can directly pass subarray to next recursion
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	inorderMap := make(map[int]int)

	for i := 0; i < len(inorder); i++ {
		inorderMap[inorder[i]] = i
	}
	return solve(preorder, 0, inorder, 0, len(inorder), inorderMap)
}

func solve(preorder []int, pivot int, inorder []int, inI int, inJ int, inorderMap map[int]int) *TreeNode {
	if pivot >= len(preorder) || inI >= inJ {
		return nil
	}

	midElement := preorder[pivot]

	found := inorderMap[midElement]
	distance := found - inI

	node := TreeNode{Val: midElement}
	node.Left = solve(preorder, pivot+1, inorder, inI, inI+distance, inorderMap)
	node.Right = solve(preorder, pivot+distance+1, inorder, inI+distance+1, inJ, inorderMap)

	return &node
}