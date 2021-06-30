class Solution {
public:
    vector<int> parent;
    
    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        parent.resize(n+1, 0);
        for (int i=1; i<=n; i++) {
            parent[i] = i;
        }
        int res = 0, count = 1;
        for (const vector<int> & conn: connections) {
            int start = find(conn[0]), end = find(conn[1]);
            if (start != end) {
                res += conn[2];
                parent[end] = start;
                count++;
                if (count == n) return res;
            }
        }
        return -1;
    }
};