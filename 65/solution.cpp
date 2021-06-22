class Solution {
public:
    bool isNumber(string s) {
        bool pointSeen = false, eSeen = false, numberSeen = false, numberAfterE = true;
        for (int i=0; i<s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if (s[i] == '.') {
                if (eSeen || pointSeen) return false;
                pointSeen = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (eSeen || !numberSeen) return false;
                numberAfterE = false;
                eSeen = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i != '0' && i > 0 && s[i-1] != 'e') return false;
            } else {
                return false;
            }
        }
        
        return numberSeen && numberAfterE;
    }
};