class Solution {
public:
    int minOperations(string s) {
        int n1 = 0, n2 = 0;
        for (int i=0; i<s.length(); i++) {
            if (i&1) {
                if (s[i] != '1') n1++;
                else n2++;
            } else {
                if (s[i] != '1') n2++;
                else n1++;
            }
        }
        return min(n1, n2);
    }
};