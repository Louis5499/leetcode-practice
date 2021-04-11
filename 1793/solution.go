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

func maximumScore(nums []int, k int) int {
	score, m := nums[k], nums[k]
	left, right := k, k
	
	for left > 0 || right < len(nums) - 1 {
			if left > 0 && right < len(nums) - 1 {
					if nums[left - 1] > nums[right + 1] {
							left--
					} else if nums[left - 1] < nums[right + 1] {
							right++
					} else {
							left--
							right++
					}
			} else if left > 0 {
					left--
			} else if right < len(nums) - 1 {
					right++
			} else {
					break
			}
			
			m = min(m, min(nums[left], nums[right]))
			score = max(score, m*(right-left+1))
	}
	
	return score
}