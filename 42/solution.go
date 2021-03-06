func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func trap(height []int) int {
	n := len(height)
	left := make([]int, n)
	right := make([]int, n)
	copy(left, height)
	copy(right, height)

	for i := 1; i < n; i++ {
		j := n - i - 1
		left[i] = max(left[i], left[i-1])
		right[j] = max(right[j], right[j+1])
	}

	sum := 0
	for idx, val := range height {
		sum += min(left[idx], right[idx]) - val
	}
	return sum
}