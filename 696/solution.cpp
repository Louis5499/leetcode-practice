class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, res = 0;
        for (int i=1; i<s.length(); i++) {
            if (s[i-1] == s[i]) cur++;
            else {
                res += min(cur, prev);
                prev = cur;
                cur = 1;
            }
        }
        res += min(prev, cur);
        return res;
    }
};