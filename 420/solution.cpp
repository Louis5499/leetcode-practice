class Solution {
public:
    int strongPasswordChecker(string s) {
        int requiredChar = getRequired(s);
        if (s.length() < 6) return max(requiredChar, (int)(6 - s.length()));
        
        int replace = 0;
        int oned = 0;
        int twod = 0;
        
        for (int i=0; i<s.length();) {
            int len = 1;
            while (i+len < s.length() && s[i+len] == s[i+len-1]) len++;
            if (len >= 3) {
                replace += len/3;
                if (len%3 == 0) oned += 1;
                if (len%3 == 1) twod += 2;
            }
            i += len;
        }
        
        if (s.length() <= 20) return max(requiredChar, replace);
        
        int deleteCount = s.length() - 20;
        
        replace -= min(deleteCount, oned);
        replace -= min(max(deleteCount-oned, 0), twod)/2;
        replace -= max(deleteCount-oned-twod, 0)/3;
        
        return deleteCount + max(requiredChar, replace);
    }
    
    int getRequired(string s) {
        int lowercase = 1, uppercase = 1, digit = 1;
        for (char c: s) {
            if (islower(c)) lowercase = 0;
            if (isupper(c)) uppercase = 0;
            if (isdigit(c)) digit = 0;
        }
        return lowercase + uppercase + digit;
    }
};