import "math/rand"

func findKthLargest(nums []int, k int) int {
	return quickSelect(nums, 0, len(nums)-1, len(nums)-k)
}

func quickSelect(nums []int, left int, right int, targetIdx int) int {
	for {
		pivot := partition(nums, left, right)

		if targetIdx == pivot {
			return nums[pivot]
		} else if pivot < targetIdx {
			left = pivot + 1
		} else {
			right = pivot - 1
		}
	}
}

func partition(nums []int, left int, right int) int {
	pivotIdx := rand.Intn(right-left+1) + left
	pivot := nums[pivotIdx]

	nums[pivotIdx], nums[right] = nums[right], nums[pivotIdx]

	storeIdx := left

	for idx := left; idx < right; idx++ {
		if nums[idx] < pivot {
			nums[idx], nums[storeIdx] = nums[storeIdx], nums[idx]
			storeIdx++
		}
	}

	nums[right], nums[storeIdx] = nums[storeIdx], nums[right]
	return storeIdx
}