class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        process(result, vector<int>{}, candidates, target, 0);
        return result;
    }
    
    void process(vector<vector<int>> &result, vector<int> curState, vector<int>& candidates, int target, int i) {
        if (target == 0) {
            result.emplace_back(curState);
            return;
        }
        if (target < 0) return;
        for (int x=i; x<candidates.size(); x++) {
            if (x > i && candidates[x] == candidates[x-1]) continue;
            curState.emplace_back(candidates[x]);
            process(result, curState, candidates, target-candidates[x], x+1);
            curState.pop_back();
        }
    }
};