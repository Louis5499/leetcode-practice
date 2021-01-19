import "sort"

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	result := make([][]int, 0)

	for firstIdx := 0; firstIdx < len(nums); firstIdx++ {
		remainTarget := target - nums[firstIdx]

		for secondIdx := firstIdx + 1; secondIdx < len(nums); secondIdx++ {
			remainSecondTarget := remainTarget - nums[secondIdx]
			left := secondIdx + 1
			right := len(nums) - 1

			for left < right {
				sum := nums[left] + nums[right]

				if sum < remainSecondTarget {
					left++
				} else if sum > remainSecondTarget {
					right--
				} else {
					ans := make([]int, 4)
					ans[0] = nums[firstIdx]
					ans[1] = nums[secondIdx]
					ans[2] = nums[left]
					ans[3] = nums[right]

					result = append(result, ans)

					for left < right && nums[left] == ans[2] {
						left++
					}

					for left < right && nums[right] == ans[3] {
						right--
					}
				}
			}

			for secondIdx < len(nums)-1 && nums[secondIdx] == nums[secondIdx+1] {
				secondIdx++
			}
		}

		for firstIdx < len(nums)-1 && nums[firstIdx] == nums[firstIdx+1] {
			firstIdx++
		}
	}

	return result
}