import "sort"

func threeSum(nums []int) [][]int {
	var res [][]int

	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		front := i + 1
		back := len(nums) - 1
		target := -(nums[i])

		if target < 0 {
			break
		}

		for front < back {
			sum := nums[front] + nums[back]

			if sum < target {
				front++
			} else if sum > target {
				back--
			} else {
				triplets := make([]int, 3)
				triplets[0] = nums[i]
				triplets[1] = nums[front]
				triplets[2] = nums[back]
				res = append(res, triplets)

				for front < back && nums[front] == triplets[1] {
					front++
				}
				for front < back && nums[back] == triplets[2] {
					back--
				}
			}
			for i < len(nums)-1 && nums[i] == nums[i+1] {
				i++
			}
		}
	}
	return res
}