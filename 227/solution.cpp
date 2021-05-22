class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, lastTerm;
        char op;
        while (in >> op) {
            if (op == '+' || op == '-') {
                total += term;
                in >> term;
                term *= (op == '-' ? -1 : 1);
            } else {
                in >> lastTerm;
                if (op == '*') {
                    term*=lastTerm;
                } else {
                    term/=lastTerm;
                }
            }
        }
        return total;
    }
};