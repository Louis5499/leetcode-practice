class Solution {
public:
    int compress(vector<char>& chars) {
        int idxAns = 0, idx = 0;
        while (idx < chars.size()) {
            char curChar = chars[idx];
            int count = 0;
            while (idx < chars.size() && curChar == chars[idx]) {
                idx++;
                count++;
            }
            chars[idxAns++] = curChar;
            if (count > 1) {
                string str = to_string(count);
                for (char c: str) {
                    chars[idxAns++] = c;
                }
            }
        }
        return idxAns;
    }
};