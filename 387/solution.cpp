class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charList;
        for (char c: s) {
            charList[c]++;
        }
        
        for (int i=0; i<s.length(); i++) {
            if (charList[s[i]] == 1) return i;
        }
        return -1;
    }
};