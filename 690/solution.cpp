/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> importance;
        unordered_map<int, vector<int>> subordinates;
        for (auto employee: employees) {
            importance[employee->id] = employee->importance;
            subordinates[employee->id] = employee->subordinates;
        }
        
        queue<int> q;
        q.push(id);
        int sum = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            sum += importance[cur];
            for (int subordinate: subordinates[cur]) {
                q.push(subordinate);
            }
        }
        return sum;
    }
};