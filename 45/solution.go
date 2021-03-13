func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func jump(nums []int) int {
	n := len(nums)
	iL, iR, step := 0, 0, 0
	for iR < n-1 {
		nextIR := 0
		for i := iL; i <= iR; i++ {
			nextIR = max(nextIR, i+nums[i])
		}
		iL = iR + 1
		iR = nextIR
		step++
	}
	return step
}