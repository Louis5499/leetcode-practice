class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        for (int i=1; i<strs.size(); i++) {
            int minLen = min(strs[i].length(), str.length());
            str = str.substr(0, minLen);
            for (int j=0; j<min(strs[i].length(), str.length()); j++) {
                if (strs[i][j] != str[j]) {
                    str = str.substr(0, j);
                    break;
                }
            }
        }
        return str;
    }
};