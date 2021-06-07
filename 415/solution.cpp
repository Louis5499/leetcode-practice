class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int carry = 0, k=0;
        for (int i=num1.length()-1, j = num2.length()-1; i>=0 || j>=0 || carry >= 1; i--, j--){
            int x = i < 0 ? 0 : num1[i] - '0';
            int y = j < 0 ? 0 : num2[j] - '0';
            sum += to_string((x+y+carry)%10);
            carry = (x+y+carry)/10;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};