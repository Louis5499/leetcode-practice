class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxSize = 0, uniqueChar = 0, j=0;
        int chars[256] = {0};
        for (int i=0; i<s.length(); i++) {
            if (++chars[s[i]] == 1) uniqueChar++;
            while (uniqueChar > k) {
                if(--chars[s[j++]] == 0) uniqueChar--;
            }
            maxSize = max(i-j+1, maxSize);
        }
        return maxSize;
    }
};