class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        for (int i=0; i<haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool isMatch = true;
                for (int j=0; j<needle.length(); j++) {
                    if (haystack[i+j] != needle[j]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) return i;
            }
        }
        return -1;
    }
};