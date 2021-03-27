class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int, int>> stk; // (value, accumulated_weight)
        
        int answer = 0;
        long long sum = 0;
        for (int val: arr) {
            int weight = 1;
            while (!stk.empty() && val < stk.top().first) {
                sum -= stk.top().first*stk.top().second;
                weight += stk.top().second;
                stk.pop();
            }
            stk.push({ val, weight });
            sum += val*weight;
            answer = (answer + sum % mod) % mod;
        }
        return answer;
    }
};