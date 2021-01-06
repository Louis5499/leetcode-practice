import (
	"math"
	"math/rand"
)

func kClosest(points [][]int, K int) [][]int {
	return quickSort(points, 0, len(points)-1, K-1)
}

func quickSort(points [][]int, left int, right int, targetIdx int) [][]int {
	for {
		pivotIdx := partition(points, left, right)

		if pivotIdx == targetIdx {
			return points[0 : targetIdx+1]
		} else if pivotIdx > targetIdx {
			right = pivotIdx - 1
		} else {
			left = pivotIdx + 1
		}
	}
}

func partition(points [][]int, left int, right int) int {
	pivotIdx := rand.Intn(right-left+1) + left
	pivot := points[pivotIdx]

	points[pivotIdx], points[right] = points[right], points[pivotIdx]

	storeIdx := left

	for i := left; i < right; i++ {
		if comparingFunc(pivot, points[i]) {
			points[storeIdx], points[i] = points[i], points[storeIdx]
			storeIdx++
		}
	}

	points[storeIdx], points[right] = points[right], points[storeIdx]

	return storeIdx
}

func comparingFunc(pointA []int, pointB []int) bool {
	return (math.Pow(float64(pointA[0]), 2) + math.Pow(float64(pointA[1]), 2)) > (math.Pow(float64(pointB[0]), 2) + math.Pow(float64(pointB[1]), 2))
}