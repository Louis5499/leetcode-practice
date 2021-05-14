class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n, 0);
        
        for (int i=0; i<n; i++) parent[i] = i;
        
        for (auto edge: edges) {
            int s = edge[0];
            int d = edge[1];
            while(parent[s] != s) s = parent[s];
            while(parent[d] != d) d = parent[d];
            if (s == d) return false; // means they have same parent
            parent[d] = s;
        }
        
        return edges.size() == n-1; // Confirm whether graph are fully connected (Assume no duplicated edges)
    }
};