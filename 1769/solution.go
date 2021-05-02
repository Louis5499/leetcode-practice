func minOperations(boxes string) []int {
	result := make([] int, len(boxes))
	
	ops, balls := 0, 0
	for idx, _ := range(boxes) {
			result[idx] += ops
			if boxes[idx] == '1' {
					balls++
			}
			ops += balls
	}
	
	ops, balls = 0, 0
	for i := len(boxes) - 1; i >= 0; i-- {
			result[i] += ops
			if boxes[i] == '1' {
					balls++
			}
			ops += balls
	}
	
	return result
}