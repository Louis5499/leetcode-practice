class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> words(numRows, "");
        int pos = 1, i = 0, j=0;
        while (j < s.length()) {
            words[i] += s[j++];
            if (i == numRows-1) pos = -1;
            else if (i == 0) pos = 1;
            i += pos;
        }
        
        string output = "";
        for (string &str: words) output += str;
        return output;
    }
};