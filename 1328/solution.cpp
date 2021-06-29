class Solution {
public:
    string breakPalindrome(string palindrome) {
        if (palindrome.length() <= 1) return "";
        bool hasChanged = false;
        for (int i=0; i<palindrome.length()/2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                hasChanged = true;
                break;
            }
        }
        if (!hasChanged) {
            palindrome[palindrome.length()-1]++;
        }
        return palindrome;
    }
};