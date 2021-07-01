class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        stack<int> myStack;
        char sign = '+';
        long number = 0;
        
        for (int i = 0; i< s.size(); i++) {
            if (isdigit(s[i])) {
                number = number*10 + long(s[i]-'0');
            } else if (s[i] == '(') {
                int j = i + 1; 
                int braces = 1;
                while (braces > 0) {
                    if (s[j] == '(')
                        braces++;
                    else if (s[j] ==')')
                        braces--;
                    j++;
                }
                
                int length = (j-1) -i ;
                number = calculate(s.substr(i + 1, length));
                i = j-1; // adjust cursor to the last calculated character
            }
            
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.size()-1) {
                switch(sign) {
                    case '+':
                        myStack.push(number);
                        break;
                    case '-':
                        myStack.push(-number);
                        break;
                    case '*': {
                        int top = myStack.top(); myStack.pop();
                        myStack.push(top*number);
                        break;
                    }
                    case '/': {
                        int top = myStack.top(); myStack.pop();
                        myStack.push(top/number);
                        break;
                    }
                }

                sign = s[i];
                number = 0;
            }
        }
        
        int sum = 0;
        while(!myStack.empty()) {
            sum += myStack.top();
            myStack.pop();
        }
        return sum;
    }
};