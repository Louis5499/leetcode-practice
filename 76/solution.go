func minWindow(s string, t string) string {
	dict := make([]int, 128)
	total := 0
	for _, v := range t {
		dict[v]++
		if dict[v] == 1 {
			total++
		}
	}

	l, answerL, answerLen := 0, 0, 0x3f3f3f3f
	for i, v := range s {
		dict[v]--
		if dict[v] == 0 {
			total--
		}

		for total == 0 {
			if i-l+1 < answerLen {
				answerL = l
				answerLen = i - l + 1
			}

			dict[s[l]]++
			if dict[s[l]] == 1 {
				total++
			}
			l++
		}
	}

	if answerLen == 0x3f3f3f3f {
		return ""
	} else {
		return s[answerL : answerL+answerLen]
	}
}