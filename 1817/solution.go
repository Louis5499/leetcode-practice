func findingUsersActiveMinutes(logs [][]int, k int) []int {
	result := make([] int, k)
	uams := make(map[int]map[int]bool)
	
	for _, log := range(logs) {
			if (uams[log[0]] == nil) {
					uams[log[0]] = make(map[int]bool)
			}
			uams[log[0]][log[1]] = true
	}
	
	for _, uam := range uams {
			if len(uam) <= k {
					result[len(uam) - 1]++
			}
	}
	
	return result
}