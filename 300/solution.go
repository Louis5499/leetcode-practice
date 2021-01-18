import "sort"

func lengthOfLIS(nums []int) int {
	ans := make([]int, 0)

	for i := 0; i < len(nums); i++ {
		target := nums[i]

		insertion := sort.IntSlice(ans).Search(target)
		if insertion == len(ans) {
			ans = append(ans, target)
		} else {
			ans[insertion] = target
		}

	}
	return len(ans)
}