import "sort"

func advantageCount(A []int, B []int) []int {
	orderedA := make([]int, len(A))
	copy(orderedA, A)
	candidate := 0
	sort.Ints(orderedA)
	for idx, val := range B {
		orderedA, candidate = findUpperBound(orderedA, val)
		A[idx] = candidate
	}
	return A
}

func findUpperBound(A []int, target int) ([]int, int) {
	for idx, val := range A {
		if target < val {
			A = append(A[:idx], A[idx+1:]...)
			return A, val
		}
	}
	// When Found nothing
	candidate := A[0]
	A = A[1:]
	return A, candidate
}