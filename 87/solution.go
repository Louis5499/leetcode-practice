func isScramble(s1 string, s2 string) bool {
	if s1 == s2 {
			return true
	}

	leng := len(s1)
	count := make([]int, 26)

	for i := 0; i < leng; i++ {
			count[s1[i]-'a']++
			count[s2[i]-'a']--
	}

	for i := 0; i < 26; i++ {
			if count[i] != 0 {
					return false
			}
	}

	for i := 1; i <= leng-1; i++ {
			if isScramble(s1[0:i], s2[0:i]) && isScramble(s1[i:], s2[i:]) {
					return true
			}
			if isScramble(s1[0:i], s2[leng-i:]) && isScramble(s1[i:], s2[0:leng-i]) {
					return true
			}
	}
	return false
}