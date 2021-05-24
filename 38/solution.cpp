class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string res = "1";
        while(--n) {
            string cur = "";
            int count = 0;
            for (int i=0; i<res.size(); i++) {
                count = 1;
                while ((i < res.size() - 1) && res[i] == res[i+1]) {
                    i++;
                    count++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};