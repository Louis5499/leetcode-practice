func twoSum(nums []int, target int) []int {
	complacencyMap := make(map[int]int)
	for idx, val := range nums {
		compleNum := target - val
		frontIdx, ok := complacencyMap[compleNum]
		if ok {
			return []int{frontIdx, idx}
		}
		complacencyMap[val] = idx
	}
	return []int{0, 0}
}