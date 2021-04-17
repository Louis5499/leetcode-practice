func abs(a int, b int) int {
	diff := a - b
	if diff < 0 {
			return -diff
	} else {
			return diff
	}
}

func max(a int, b int) int {
	if a > b {
			return a
	} else {
			return b
	}
}

func minAbsoluteSumDiff(nums1 []int, nums2 []int) int {
	sum, gain, sorted := 0, 0, []int{}
	
	for _, num := range nums1 {
			idx := sort.SearchInts(sorted, num)
			
			if len(sorted) > 0 && idx < len(sorted) && sorted[idx] == num {
					continue
			}
			
			sorted = append(sorted, num)
	}
	
	sort.Ints(sorted)

	for idx, val := range(nums1) {
			diff := abs(val, nums2[idx]);
			sum += diff
			if gain < diff {
					candI := sort.SearchInts(sorted, nums2[idx])
					
					if candI < len(sorted) {
							gain = max(gain, diff - abs(sorted[candI], nums2[idx]))
					}
					
					if candI > 0 {
							gain = max(gain, diff - abs(sorted[candI-1], nums2[idx]))
					}
			}
	}
	return (sum - gain)%1000000007
}