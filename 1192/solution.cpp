class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for (auto& conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(conn[0]);
        }
        
        int ranks[n];
        fill_n(ranks, n, -2);
        vector<vector<int>> result;


        criticalConnections(graph, n, 0, 0, ranks, result);        
        
        return result;
    }
private:

    int criticalConnections(vector<int> graph[], int n, int node, int myRank, int ranks[], vector<vector<int>>& result) {
        if (ranks[node] != -2) {
            return ranks[node];
        }

        int lowestRank = myRank;
        ranks[node] = myRank;
        for (auto neighbor : graph[node]) {
            if (ranks[neighbor] == myRank - 1 || ranks[neighbor] == n) {
                continue;
            }
            
            int neighborRank = criticalConnections(graph, n, neighbor, myRank + 1, ranks, result);
            lowestRank = min(lowestRank, neighborRank);
            if (neighborRank > myRank) {
                result.push_back({min(node, neighbor), max(node, neighbor)});
            }
            
        }
        
        ranks[node] = n;
        return lowestRank;
    }
};