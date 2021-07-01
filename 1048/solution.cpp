class Solution {
public:
    vector<string> findAllWords(string &a) {
        vector<string> output;
        for (int i=0; i<a.size(); i++) {
            output.emplace_back(a.substr(0, i) + a.substr(i+1, a.size()-i-1));
        }
        return output;
    }

    int longestStrChain(vector<string>& words) {
        vector<vector<string>> levels(17);
        unordered_map<string, int> mp;
        for (string &word: words) {
            levels[word.size()].emplace_back(word);
            mp[word] = 1;
        }
        
        int ans = 1;
        for (int i=2; i<17; i++) {
            for (string &level: levels[i]) {
                vector<string> expandedLevel = findAllWords(level);
                for (string &word: expandedLevel) {
                    if (mp.find(word) != mp.end()) mp[level] = max(mp[word] + 1, mp[level]);    
                }
                ans = max(mp[level], ans);
            }
        }
        return ans;
    }
};