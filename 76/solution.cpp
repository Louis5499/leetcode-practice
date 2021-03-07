class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(128);
        int total = 0; // Count how many char has the record
        for (auto c: t) {
            dict[c]++;
            if (dict[c] == 1) total++;
        }
        
        int l = 0;
        int answerL = 0, answerLen = 0x3f3f3f3f;
        for (int i=0; i<s.length(); i++) {
            if (--dict[s[i]] == 0) total--;
            while (!total) {
                if (i - l + 1 < answerLen) {
                    answerL = l;
                    answerLen = i - l + 1;
                }
                
                if (++dict[s[l++]] == 1) total++;
            }
        }
        
        if (answerLen == 0x3f3f3f3f) return "";
        else return s.substr(answerL, answerLen);
        
    }
};