func min(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

func coinChange(coins []int, amount int) int {
	Max := amount + 1
	dp := make([]int, amount+1)
	for idx, _ := range dp {
		dp[idx] = Max
	}

	dp[0] = 0
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			dp[i] = min(dp[i], dp[i-coin]+1)
		}
	}

	if dp[amount] > amount {
		return -1
	} else {
		return dp[amount]
	}
}