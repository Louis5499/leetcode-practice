// Optimization method
// 1. Transform wordDict to dictionary, not vector
// 2. Utilize DP to solve the problem, not pure recursion.

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        set<string> wordDictSet(wordDict.begin(), wordDict.end());
        
        for (int i=1; i <= s.size(); i++) {
            for (int j=i-1; j>=0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (wordDictSet.find(word) != wordDictSet.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};