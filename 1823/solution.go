func findTheWinner(n int, k int) int {
	nums := make([] int, n)
	for i, _ := range(nums) {
			nums[i] = i + 1
	}
	
	remaining, cursor := n, 0
	for remaining > 1 {
			cursor = (cursor + k - 1)%remaining
			nums = append(nums[:cursor], nums[cursor+1:]...)
			remaining--
	}
	
	return nums[0]
}