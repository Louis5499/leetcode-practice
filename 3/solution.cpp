class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 0) return 0;
        map<char, int> mapping;
        int count = 0;
        for (int i=0, j=0; i<s.length(); i++) {
            if (mapping.find(s[i]) != mapping.end()) {
                j = max(j, mapping[s[i]]+1);
            }
            mapping[s[i]] = i;
            count = max(count, i-j+1);
        }
        return count;
    }
};