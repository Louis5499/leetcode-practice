const mod = 1e9 + 7

type Pair struct {
    value, weight interface{}
}

func sumSubarrayMins(arr []int) int {
    stk := make([] Pair, 0)
    
    answer, sum := 0, 0
    for _, val := range(arr) {
        weight := 1
        for len(stk) > 0 && val < stk[len(stk) - 1].value.(int) {
            sum -= stk[len(stk) - 1].value.(int)*stk[len(stk) - 1].weight.(int)
            weight += stk[len(stk) - 1].weight.(int)
            stk = stk[:len(stk) - 1]
        }
        stk = append(stk, Pair{val, weight})
        sum += val*weight
        answer = (answer + sum % mod) % mod
    }
    return answer
}