class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for (int num: nums) res.emplace_back(to_string(num));
        sort(begin(res), end(res), [](string &s1, string &s2){ return s1+s2 > s2+s1; });
        string finalWord = "";
        for (string str: res) finalWord += str;
        while(finalWord[0] == '0' && finalWord.length() > 1) finalWord.erase(0, 1);
        return finalWord;
    }
};