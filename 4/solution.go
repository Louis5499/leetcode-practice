func min(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func findKMostVal(nums1 []int, nums2 []int, m int, n int, k int) int {
	if m == 0 {
		return nums2[k-1]
	} else if n == 0 {
		return nums1[k-1]
	} else if k == 1 {
		return min(nums1[0], nums2[0])
	} else {
		halfIdx := k / 2
		mIdx := min(m, halfIdx)
		nIdx := min(n, halfIdx)

		if nums1[mIdx-1] > nums2[nIdx-1] {
			return findKMostVal(nums1, nums2[nIdx:], m, n-nIdx, k-nIdx)
		} else {
			return findKMostVal(nums1[mIdx:], nums2, m-mIdx, n, k-mIdx)
		}
	}

}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m := len(nums1)
	n := len(nums2)
	if (m+n)&1 == 1 {
		// the total length of two arr is odd
		return float64(findKMostVal(nums1, nums2, m, n, (m+n)/2+1))
	} else {
		// the total length of two arr is even
		return (float64(findKMostVal(nums1, nums2, m, n, (m+n)/2)) + float64(findKMostVal(nums1, nums2, m, n, (m+n)/2+1))) / 2
	}
}

