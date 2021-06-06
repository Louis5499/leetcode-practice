class Solution {
private:
    unordered_set<string> pool;
    unordered_map<string, vector<string>> m;

    vector<string> combine(string back, vector<string> prevArr) {
        for (int i=0; i<prevArr.size(); i++) {
            prevArr[i] += " " + back;
        }
        return prevArr;
    }
public:
    vector<string> breaking(string s) {
        if (m.find(s) != m.end()) return m[s];
        vector<string> result;
        
        if (pool.find(s) != pool.end()) result.emplace_back(s); // Whole string
        for (int i=1; i<s.length(); i++) {
            string backStr = s.substr(i);
            if (pool.find(backStr) != pool.end()) {
                vector<string> perResult = combine(backStr, breaking(s.substr(0, i)));
                result.insert(result.end(), perResult.begin(), perResult.end());
            }
        }
        m[s] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        pool = unordered_set<string>(wordDict.begin(), wordDict.end());
        return breaking(s);
    }
};