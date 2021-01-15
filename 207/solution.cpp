class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegreeNum(numCourses, 0);
        queue<int> q;
        
        // Build adjency information
        for (auto &prerequisite: prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            inDegreeNum[prerequisite[0]]++;
        }
    
        // Find starting point
        for (int i=0; i<numCourses; i++) {
            if (inDegreeNum[i] == 0) q.push(i);
        }
        
        
        // Topology sort
        while(!q.empty()) {
            // Get the first element
            int candidate = q.front();
            q.pop();
            numCourses--;
            
            // Traverse first element
            for (auto linkedElement: adj[candidate]) {
                if (--inDegreeNum[linkedElement] <= 0) q.push(linkedElement);
            }
        }
        
        return numCourses == 0;
    }
};