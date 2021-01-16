func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func rob(nums []int) int {
	if len(nums) <= 0 {
		return 0
	}

	prev := 0
	cur := nums[0]

	for i := 1; i < len(nums); i++ {
		tmp := cur
		cur = max(cur, prev+nums[i])
		prev = tmp
	}

	return cur
}