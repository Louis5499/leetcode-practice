class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxSize = 0;

        for (int alpha=1; alpha<=26; alpha++) {
            vector<int> chars(26, 0);
            int i=0, j=0;
            int noLessThanK = 0, uniqueChar = 0;
            while (j <= s.length()-1) {
                if (uniqueChar<=alpha) {
                    if (++chars[s[j]-'a'] == 1) uniqueChar++;
                    if (chars[s[j]-'a'] == k) noLessThanK++;
                    j++;
                } else {
                    if (--chars[s[i]-'a'] == 0) uniqueChar--;
                    if (chars[s[i]-'a'] == k-1) noLessThanK--;
                    i++;
                }
                if (uniqueChar == alpha && uniqueChar == noLessThanK) {
                    maxSize = max(j-i, maxSize);
                }
            }
        }
        return maxSize;
    }
};