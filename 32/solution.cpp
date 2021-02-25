class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int left = -1;
        stk.push(left);
        int ans = 0;
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                stk.push(i);
            } else {
                if (stk.top() == left) {
                    stk.push(i);
                    left = i;
                } else {
                    stk.pop();
                    ans = max(ans, i-stk.top());
                }
            }
        }
        return ans;
    }
};