func containsDuplicate(nums []int) bool {
	m := make(map[int]bool)
	
	for _, val := range(nums) {
			_, ok := m[val]
			if !ok {
					m[val] = true
			} else {
					return true
			}
	}
	
	return false
}