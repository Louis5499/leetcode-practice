func minSteps(n int) int {
	dp := make([]int, n+1)

	for i := 2; i <= n; i++ {
		for j := i / 2; j >= 1; j-- {
			if i%j == 0 {
				dp[i] = dp[j] + i/j
				break
			}
		}
	}

	return dp[n]
}