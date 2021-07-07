class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        queue<pair<int, int>> bfs;
        bfs.push({source, 0});
        unordered_set<int> seen = {source};
        while (!bfs.empty()) {
            int stop = bfs.front().first, bus = bfs.front().second; bfs.pop();
            if (stop == target) return bus;
            for (auto i: to_routes[stop]) {
                for (auto busStop: routes[i]) {
                    if (seen.count(busStop) == 0) {
                        seen.insert(busStop);
                        bfs.push({busStop, bus+1});
                    }
                }
                routes[i].clear();
            }
        }
        
        return -1;
    }
};