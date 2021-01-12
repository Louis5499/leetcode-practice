func getMax(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func getMin(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func maxArea(height []int) int {
	i := 0
	j := len(height) - 1
	maxVal := 0

	for i < j {
		maxVal = getMax(maxVal, (j-i)*getMin(height[i], height[j]))

		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}

	return maxVal
}