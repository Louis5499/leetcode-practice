class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> nums;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int last = stoi(nums.top()); nums.pop();
                int last2 = stoi(nums.top()); nums.pop();
                int result;
                if (token == "+") result = last2 + last;
                else if (token == "-") result = last2 - last;
                else if (token == "*") result = last2 * last;
                else if (token == "/") result = last2 / last;
                nums.push(to_string(result));
            } else {
                nums.push(token);
            }
        }
        return stoi(nums.top());
    }
};