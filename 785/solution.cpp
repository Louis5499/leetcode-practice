class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        
        queue<int> q;
        for (int i=0; i<graph.size(); i++) {
            if (color[i]) continue;
            
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                for (int neighbor: graph[cur]) {
                    if (color[neighbor] == 0) {
                        color[neighbor] = -color[cur];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[cur]) return false;
                }
            }
            
        }
        
        return true;
    }
};