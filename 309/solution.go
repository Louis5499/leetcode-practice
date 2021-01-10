func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	s0 := 0
	s1 := -prices[0]
	s2 := -99999999
	for i := 1; i < len(prices); i++ {
		prev_s0 := s0
		s0 = Max(s0, s2)
		s2 = s1 + prices[i]
		s1 = Max(prev_s0-prices[i], s1)
	}
	return Max(s0, s2)
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}