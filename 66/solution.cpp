class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]++;
        while (--n) {
            if (digits[n] >= 10) {
                digits[n-1]++;
                digits[n] = 0;
            }
        }
        if (digits[0] >= 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};