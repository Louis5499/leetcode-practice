func removeKdigits(num string, k int) string {
	ans := ""
	
	for _, digit := range(num) {
			for k > 0 && len(ans) > 0 && int(ans[len(ans) - 1]) > int(digit) {
					ans = ans[:len(ans) - 1]
					k--
			}
			
			if digit != '0' || len(ans) != 0 {
					ans += string(digit)
			}
	}
	
	for k > 0 && len(ans) > 0 {
			ans = ans[:len(ans) - 1]
			k--
	}
	
	if len(ans) > 0 {
			return ans
	} else {
			return "0"
	}
}