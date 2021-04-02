class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        
        for (char digit: num) {
            while (!ans.empty() && ans.back() > digit && k) {
                ans.pop_back();
                k--;
            }
            if (!ans.empty() || digit != '0') ans.push_back(digit);
        }
        
        while (k && !ans.empty()) {
            ans.pop_back();
            k--;
        }
        
        return ans.length() > 0 ? ans : "0"; 
    }
};