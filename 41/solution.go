func firstMissingPositive(nums []int) int {
	n := len(nums)
	for idx, _ := range nums {
		for nums[idx] > 0 && nums[idx] < n && nums[nums[idx]-1] != nums[idx] {
			temp := nums[nums[idx]-1]
			nums[nums[idx]-1] = nums[idx]
			nums[idx] = temp
		}
	}

	for idx, val := range nums {
		if val != idx+1 {
			return idx + 1
		}
	}
	return n + 1
}