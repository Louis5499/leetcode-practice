class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> times;
        for (int i=0; i<keyName.size(); i++) {
            times[keyName[i]].emplace_back(stoi(keyTime[i].substr(0, 2))*60 + stoi(keyTime[i].substr(3)));
        }
        
        vector<string> result;
        for (auto &p: times) {
            sort(p.second.begin(), p.second.end());
            for (int i=2, j=0; i<p.second.size(); i++) {
                while (p.second[i] - p.second[j] > 60) j++;
                if (i-j >= 2) {
                    result.emplace_back(p.first);
                    break;
                }
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};