class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char c: s) m[c]++;
        bool hasOdd = false;
        for (auto it: m) {
            if (it.second & 1) {
                if (hasOdd) return false;
                hasOdd = true;
            }
        }
        return true;
    }
};