class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int cost = 0;
        while (pq.size() > 1) {
            int firstSmallest = pq.top(); pq.pop();
            int secondSmallest = pq.top(); pq.pop();
            int sum = firstSmallest + secondSmallest;
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};