class Solution {
public:
    vector<int> debt;
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for (vector<int> &perTx: transactions) {
            int from = perTx[0], to = perTx[1], amount = perTx[2];
            balances[from] -= amount;
            balances[to] += amount;
        }
        
        for (auto it: balances) {
            if (it.second) debt.emplace_back(it.second);
        }
        
        return dfs(0);
    }
    
    int dfs(int start) {
        int res = INT_MAX;
        while (start < debt.size() && debt[start] == 0) start++;
        for (int i=start+1; i<debt.size(); i++) {
            if (debt[start]*debt[i] < 0) {
                debt[i] += debt[start];
                res = min(res, 1 + dfs(start+1));
                debt[i] -= debt[start];
            }            
        }
        return res == INT_MAX ? 0 : res;
    }
};