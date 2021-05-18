class Solution {
public:
    int maxL = 0, maxLen = 0;
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;

        for (int i=0; i<s.length()-1; i++) {
            finding(s, i, i);
            finding(s, i, i+1);
        }
        return s.substr(maxL, maxLen);
    }
    
    void finding(string s, int i, int j) {
        while (i >= 0 && j <= s.length()-1 && s[i] == s[j]) {
            i--;
            j++;
        }
        if (maxLen < j-i-1) {
            maxL = i+1;
            maxLen = j-i-1;
        }
    }
};