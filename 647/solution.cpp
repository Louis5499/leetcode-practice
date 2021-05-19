class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        if (s.length() < 2) return 1;

        for (int i=0; i<s.length()-1; i++) {
            finding(s, i, i);
            finding(s, i, i+1);
        }
        return count+1;
    }
    
    void finding(string s, int i, int j) {
        while (i >= 0 && j <= s.length()-1 && s[i] == s[j]) {
            i--;
            j++;
            count++;
        }
    }
};