class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        unordered_map<string, map<string, double>> equation;
        for (int i=0; i<equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            equation[u][u] = 1.0;
            equation[v][v] = 1.0;
            equation[u][v] = values[i];
            equation[v][u] = 1/values[i];
        }
        
        vector<double> result;
        set<string> visited;
        for (vector<string> &query: queries) {
            result.emplace_back(findPath(query[0], query[1], equation, visited));
        }
        
        return result;
    }
    
    double findPath(string start, string end, unordered_map<string, map<string, double>> &equation, set<string> visited) {
        if (equation.find(start) == equation.end()) {
            return -1.0;
        }
        
        if (equation[start].find(end) != equation[start].end()) {
            // Find a directly connected path
            return equation[start][end];
        }
        
        visited.insert(start);
        for (auto connected: equation[start]) {
            if (!visited.count(connected.first)) {
                double gainWeight = findPath(connected.first, end, equation, visited);
                if (gainWeight != -1.0) return connected.second*gainWeight;
            }
        }
        
        return -1.0;
    }
};