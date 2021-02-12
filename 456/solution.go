import "math"

func find132pattern(nums []int) bool {
	s3 := math.MinInt32
	st := make([]int, 0)
	for i := len(nums) - 1; i >= 0; i-- {
		if nums[i] < s3 {
			return true
		} else {
			for len(st) > 0 && nums[i] > st[len(st)-1] {
				s3 = st[len(st)-1]
				st = st[:len(st)-1]
			}
		}
		st = append(st, nums[i])
	}

	return false
}