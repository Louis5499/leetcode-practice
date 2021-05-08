func productExceptSelf(nums []int) []int {
	res := make([] int, len(nums))
	res[0] = 1
	for i := 1; i < len(nums); i++ {
			res[i] = 1
			res[i] = nums[i-1]*res[i-1]
	}
	right := 1
	for i := len(nums) - 1; i >= 0; i-- {
			res[i] *= right
			right *= nums[i]
	}
	return res
}