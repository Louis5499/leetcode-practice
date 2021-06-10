class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(isConnected.size(), 0);
        
        int count = 0;
        for (int i=0; i<n; i++) {
            if (!visited[i]) dfs(isConnected, visited, ++count, i);
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<int> &visited, int count, int i) {
        visited[i] = count;
        for (int j=0; j<isConnected[i].size(); j++) {
            if (i != j && isConnected[i][j] && visited[j] == 0) {
                dfs(isConnected, visited, count, j);
            }
        }
    }
};