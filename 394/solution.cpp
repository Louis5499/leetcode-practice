class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for (char c: s) {
            if (c == ']') {
                string concated = "";
                while (!isdigit(stk.top())) {
                    if (stk.top() != '[') concated = stk.top() + concated;
                    stk.pop();
                }
                
                string num = "";
                while (!stk.empty() && isdigit(stk.top())) {
                    num = stk.top() + num;
                    stk.pop();
                }
                int repeatedTimes = stoi(num);
                for (int i=0; i<repeatedTimes; i++) {
                    for (char concat: concated) stk.push(concat);    
                }
            }
            else stk.push(c);
        }
        
        string output = "";
        while (!stk.empty()) {
            output = stk.top() + output;
            stk.pop();
        }
        return output;
    }
};