class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string arr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string cur;
        combine(arr, digits, 0, cur, res);
        return res;
    }
    void combine(string *arr, string digits, int idx, string cur, vector<string> & res) {
        if (idx >= digits.length()) {
            if (cur.length() > 0) res.emplace_back(cur);
            return;
        }
        int num = digits[idx] - '0';
        for (int i=0; i<arr[num].length(); i++) {
            combine(arr, digits, idx+1, cur+arr[num][i], res);
        }
    }
};