var solutions [][] string

func solver(col []int, n int) {
    row := len(col)
    
    if row == n {
        solution := make([] string, 0)
        for i:=0; i<n; i++ {
            s := ""
            for j:=0; j<n; j++ {
                if col[i] == j {
                    s += string('Q')
                } else {
                    s += string('.')
                }
            }
            solution = append(solution, s)
        }
        solutions = append(solutions, solution)
        return
    }
    
    
    for i:=0; i<n; i++ {
        ok := true
        for j:=0; j<row; j++ {
            if col[j] == i || j + col[j] == row + i || j - col[j] == row - i {
                ok = false
                break
            }
        }
        
        if ok {
            col = append(col, i)
            solver(col, n)
            col = col[:len(col) - 1]
        }
    }
}

func solveNQueens(n int) [][]string {
    solutions = [][]string{}
    col := make([] int, 0)
    solver(col, n)
    return solutions
}