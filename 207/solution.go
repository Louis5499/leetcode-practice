func canFinish(numCourses int, prerequisites [][]int) bool {
	// Initialized Value
	adj := make([][]int, numCourses)
	inDegreeNum := make([]int, numCourses)
	q := make([]int, 0)

	for i := 0; i < numCourses; i++ {
		inDegreeNum[i] = 0
	}

	// Build Adjency Matrix
	for i := 0; i < len(prerequisites); i++ {
		pair := prerequisites[i]
		adj[pair[1]] = append(adj[pair[1]], pair[0])
		inDegreeNum[pair[0]]++
	}

	// Find Starting Points
	for i := 0; i < numCourses; i++ {
		if inDegreeNum[i] == 0 {
			q = append(q, i)
		}
	}

	for len(q) > 0 {
		// Get first Element
		candidate := q[0]
		q = q[1:]
		numCourses--

		// Traverse
		for _, val := range adj[candidate] {
			inDegreeNum[val]--
			if inDegreeNum[val] == 0 {
				q = append(q, val)
			}
		}
	}

	return numCourses == 0
}