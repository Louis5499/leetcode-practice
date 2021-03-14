func insert(intervals [][]int, newInterval []int) [][]int {
    for _, interval := range(intervals) {
        if interval[0] <= newInterval[0] && newInterval[0] <= interval[1] {
            newInterval[0] = interval[0]
        }
        if interval[0] <= newInterval[1] && newInterval[1] <= interval[1] {
            newInterval[1] = interval[1]
        }
    }
    
    
    newIntervals := make([][] int, 0)
    newIntervals = append(newIntervals, newInterval)
    for _, interval := range(intervals) {
        if !(newInterval[0] <= interval[0] && interval[1] <= newInterval[1]) {
            if interval[1] < newInterval[0] {
                newIntervals[len(newIntervals) - 1] = interval
                newIntervals = append(newIntervals, newInterval)
            } else {
                newIntervals = append(newIntervals, interval)
            }
        }
    }
    
    return newIntervals
}