class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return compareSubStr(s, wordDict, 0);
    }
    
    bool compareSubStr(string s, vector<string>& wordDict, int frontIdx) {
        int originalFrontIdx = frontIdx;
        bool ans = false;
        for (vector<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            string extractedWord = *it;
            bool correct = true;
            frontIdx = originalFrontIdx;
            if (extractedWord[0] == s[frontIdx]) {
                for (int innerIdx = 0; innerIdx < extractedWord.size(); innerIdx++) {
                    if (extractedWord[innerIdx] != s[frontIdx++]) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    if (frontIdx == s.size()) return true;
                    else ans |= compareSubStr(s, wordDict, frontIdx);
                }
            }
        }
        return ans;
    }
};