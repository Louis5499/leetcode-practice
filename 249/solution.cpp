class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> pool;
        for (string &pending: strings) {
            string proc = "0";
            for (int i=1; i<pending.length(); i++) {
                int offset = pending[i] - pending[0];
                if (offset < 0) offset += 26;
                string stringified = offset < 10 ? "0" + to_string(offset) : to_string(offset);
                proc += stringified;
            }
            pool[proc].emplace_back(pending);
        }
        
        vector<vector<string>> output;
        for (auto &element: pool) {
            output.emplace_back(element.second);
        }
        return output;
    }
};