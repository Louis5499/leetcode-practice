class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegrees(numCourses, 0);
        
        for (auto prerequisite: prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            inDegrees[prerequisite[0]]++;
        }
        
        
        for (int i=0; i<inDegrees.size(); i++) {
            if (inDegrees[i] == 0) q.push(i);
        }
        
        vector<int> output;
        while(!q.empty()) {
            int course = q.front();
            output.push_back(course);
            q.pop();
            numCourses--;
            
            for (int relatedCourse: adj[course]) {
                if (--inDegrees[relatedCourse] <= 0) q.push(relatedCourse);
            }
        }
        
        return numCourses == 0 ? output : vector<int>();
    }
};