class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int start = 0, maxCount = 0, maxLength = 0;
        for (int end=0; end<s.length(); end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            if (end-start+1 - maxCount > k) {
                count[s[start] - 'A']--;
                start++;
            }
            maxLength = max(maxLength, end-start+1);
        }
        return maxLength;
    }
};