func min(a int, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}

type Pair struct {
	x int
	y int
}

func updateMatrix(matrix [][]int) [][]int {
	m := len(matrix)
	n := len(matrix[0])
	farestDist := m + n

	pendingQ := make([]Pair, 0)
	mat := make([][]int, m)
	for i := range mat {
		mat[i] = make([]int, n)
	}

	for i, row := range matrix {
		for j, val := range row {
			if val == 0 {
				pos := Pair{i, j}
				pendingQ = append(pendingQ, pos)
				mat[i][j] = 0
			} else {
				mat[i][j] = farestDist
			}
		}
	}

	dirs := [][]int{
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
	}

	for len(pendingQ) != 0 {
		axis := pendingQ[0]
		pendingQ = pendingQ[1:]

		for _, dir := range dirs {
			xAxis := axis.x + dir[0]
			yAxis := axis.y + dir[1]

			if xAxis >= 0 && xAxis < m && yAxis >= 0 && yAxis < n {
				if mat[xAxis][yAxis] == farestDist {
					pos := Pair{xAxis, yAxis}
					pendingQ = append(pendingQ, pos)
				}

				mat[xAxis][yAxis] = min(mat[xAxis][yAxis], mat[axis.x][axis.y]+1)
			}
		}
	}
	return mat
}