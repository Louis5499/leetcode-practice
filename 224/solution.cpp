class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int result = 0, number = 0, sign = 1;
        for (char cur: s) {
            if (isdigit(cur)) {
                number = 10*number + (cur-'0');
            } else if (cur == '+') {
                result += sign*number;
                number = 0;
                sign = 1;
            } else if (cur == '-') {
                result += sign*number;
                number = 0;
                sign = -1;
            } else if (cur == '(') {
                nums.push(result);
                nums.push(sign);
                result = 0;
                sign = 1;
            } else if (cur == ')') {
                result += sign*number;
                number = 0;
                result *= nums.top(); nums.pop(); // sign
                result += nums.top(); nums.pop(); // result
            }
        }
        if (number != 0) result += sign*number;
        return result;
    }
};