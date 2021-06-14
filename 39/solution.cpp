class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        process(result, vector<int>{}, candidates, target, 0);
        return result;
    }
    
    void process(vector<vector<int>> &result, vector<int> curState, vector<int>& candidates, int target, int i) {
        if (target == 0) {
            result.emplace_back(curState);
            return;
        }
        if (i>=candidates.size()) return;
        process(result, curState, candidates, target, i+1); // X Select
        while (target >= candidates[i]) {
            curState.emplace_back(candidates[i]);
            target -= candidates[i];
            process(result, curState, candidates, target, i+1);
        }
    }
};