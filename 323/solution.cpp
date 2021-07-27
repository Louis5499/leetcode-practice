class Solution {
public:
    unordered_map<int, int> m;
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i=0; i<n; i++) m[i] = i;
        
        for (vector<int> &edge: edges) {
            int s = find(edge[0]);
            int d = find(edge[1]);
            if (s != d) {
                m[d] = m[s];
                n--;
            }
        }
        
        return n;
    }
    
    int find(int id) {
        while (m[id] != id) {
            m[id] = m[m[id]];
            id = m[id];
        }
        return id;
    }
};