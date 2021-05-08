func min(a int, b int) int {
	if a > b {
			return b
	} else {
			return a
	}
}

func max(a int, b int) int {
	if a < b {
			return b
	} else {
			return a
	}
}

func maxProfit(prices []int) int {
	minPrice := 100001
	maxPro := 0
	
	for i := 0; i < len(prices); i++ {
			minPrice = min(minPrice, prices[i])
			maxPro = max(maxPro, prices[i] - minPrice)
	}
	
	return maxPro
}