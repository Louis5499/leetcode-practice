func wordBreak(s string, wordDict []string) bool {
	wordDictSet := make(map[string]bool)
	for _, val := range wordDict {
		wordDictSet[val] = true
	}

	dp := make([]bool, len(s)+1)

	dp[0] = true

	for i := 1; i <= len(s); i++ {
		for j := i - 1; j >= 0; j-- {
			if dp[j] {
				word := s[j:i]
				if wordDictSet[word] {
					dp[i] = true
					break
				}
			}
		}
	}

	return dp[len(s)]
}