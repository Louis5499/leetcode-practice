class Solution {
public:
    int maxEvents(vector<vector<int>>& A) {
        priority_queue <int, vector<int>, greater<int>> pq;
        sort(A.begin(), A.end());
        int i = 0, res = 0, n = A.size(), day = 1;
        while (pq.size() || i < n) {
            if (pq.size() == 0) day = A[i][0];
            while (i < n && A[i][0] <= day) {
                pq.push(A[i++][1]);
            }
            pq.pop();
            res++; day++;
            while (pq.size() && pq.top() < day) pq.pop();
        }
        return res;
    }
};