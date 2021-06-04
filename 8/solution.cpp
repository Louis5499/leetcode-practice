class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i=0;
        while (s[i] == ' ') i++;
        if (s[i] == '+' || s[i] == '-') {
            sign *= (s[i++] == '-' ? -1 : 1);
        }
        for (; i<s.length(); i++) {
            char c = s[i];
            if (c < '0' || c > '9') break;
            else {
                if (num > INT_MAX/10 || (num == INT_MAX/10 && c-'0' > INT_MAX%10)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                num *= 10;
                num += c - '0';
            }
        }
        return sign*num;
    }
};