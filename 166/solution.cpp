class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        string res = "";

        if (numerator < 0 ^ denominator < 0) res += '-';
        long long n = abs(numerator), d = abs(denominator);
        
        // Decimal Part
        res += to_string(n/d);
        
        if (n%d == 0) return res;
        res += '.';
            
        unordered_map<long long, int> m;
        for (long long r=n%d; r>0; r%=d) {
            if (m.count(r) > 0) {
                res.insert(m[r], 1, '(');
                res += ')';
                break;
            }
            
            m[r] = res.size();
            r*=10;
            res += to_string(r/d);
        }
        
        return res;
    }
};