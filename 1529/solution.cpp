class Solution {
public:
    int minFlips(string target) {
        char lastC = '0';
        int res = 0;
        for (char c: target) {
            if (c != lastC) {
                res++;
                lastC = lastC == '1' ? '0' : '1';
            }
        }
        return res;
    }
};