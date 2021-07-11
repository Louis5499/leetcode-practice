class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.length() == 0) return s.length() == 0;
        int i=0, j=0;
        while (i < s.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                if (j < t.length()-1) j++;
                else return false;
            }
        }
        return i == s.length();
    }
};