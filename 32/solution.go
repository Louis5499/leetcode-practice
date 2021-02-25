func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func longestValidParentheses(s string) int {
	left := -1
	ans := 0
	stack := make([]int, 0)
	stack = append(stack, left)
	for i, v := range s {
		if v == '(' {
			stack = append(stack, i)
		} else {
			if stack[len(stack)-1] == left {
				stack = append(stack, i)
				left = i
			} else {
				stack = stack[:len(stack)-1]
				ans = max(ans, i-stack[len(stack)-1])
			}
		}
	}
	return ans
}