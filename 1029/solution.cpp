class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
        int sum = 0;
        for (int i=0; i<costs.size(); i++) {
            vector<int> &cost = costs[i];
            if (cost[0] > cost[1]) {
                sum += cost[1];
                pq2.push(make_pair(cost[0] - cost[1], i));
            } else {
                sum += cost[0];
                pq1.push(make_pair(cost[1] - cost[0], i));
            }
        }
        
        while (pq1.size() > pq2.size()) {
            pair<int, int> top = pq1.top(); pq1.pop();
            pq2.push(make_pair(costs[top.second][0], top.second));
            sum += top.first;
        }
        
        while (pq1.size() < pq2.size()) {
            pair<int, int> top = pq2.top(); pq2.pop();
            pq1.push(make_pair(costs[top.second][1], top.second));
            sum += top.first;
        }
        return sum;
    }
};