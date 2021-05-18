class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() > s.length()) return false;
        vector<int> count(26, 0);
        int total = 0;
        for (auto c: s) {
            if (++count[c - 'a'] == 1) total++;
        }
        
        for (auto c: t) {
            if (--count[c - 'a'] == 0) total--;
        }
        return total == 0;
    }
};