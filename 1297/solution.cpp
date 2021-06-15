class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int i=0, j=0, count=0, uniqueAlpha=0;
        unordered_map<char, int> existAlpha;
        unordered_map<string, int> ans;
        while (j < s.length()) {
            if (existAlpha[s[j++]]++ == 0) uniqueAlpha++;
            while (uniqueAlpha > maxLetters || (j-i) > minSize) {
                if (--existAlpha[s[i++]] == 0) uniqueAlpha--;
            }
            if (j-i == minSize) {
                count = max(count, ++ans[s.substr(i, j-i)]);
            }
        }
        return count;
    }
};