func findAnagrams(s string, p string) []int {
	pv := make([]int, 26)
	sv := make([]int, 26)
	ans := make([]int, 0)

	if len(s) < len(p) {
		return ans
	}

	for i := 0; i < len(p); i++ {
		sv[charToInt(s[i])]++
		pv[charToInt(p[i])]++
	}

	if isSliceEqual(pv, sv) {
		ans = append(ans, 0)
	}

	for i := len(p); i < len(s); i++ {
		sv[charToInt(s[i])]++
		sv[charToInt(s[i-len(p)])]--

		if isSliceEqual(pv, sv) {
			ans = append(ans, i-len(p)+1)
		}
	}

	return ans
}

func isSliceEqual(a []int, b []int) bool {
	for idx, val := range a {
		if val != b[idx] {
			return false
		}
	}
	return true
}

func charToInt(char uint8) int {
	return int(char - 'a')
}