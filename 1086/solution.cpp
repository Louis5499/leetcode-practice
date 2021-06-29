class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> m;
        for (vector<int> & item: items) {
            m[item[0]].emplace_back(item[1]);
        }
        
        vector<vector<int>> output;
        for (auto &mapping: m) {
            sort(mapping.second.begin(), mapping.second.end(), greater<int>());
            int i, sum=0;
            for (i=0; i<5 && i<mapping.second.size(); i++) {
                sum += mapping.second[i];
            }
            output.emplace_back(vector<int>{ mapping.first, sum/i });
        }
        sort(output.begin(), output.end());
        return output;
    }
};