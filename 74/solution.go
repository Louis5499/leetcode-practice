func searchMatrix(matrix [][]int, target int) bool {
	n := len(matrix)
	m := len(matrix[0])
	left := 0
	right := n*m - 1
	for left < right {
		mid := (left + right - 1) >> 1
		if matrix[mid/m][mid%m] < target {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return matrix[right/m][right%m] == target
}