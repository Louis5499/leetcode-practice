class Solution {
public:
    const string below_20[20] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const string below_100[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return intToString(num).substr(1);
    }
    
    string intToString(int n) {
        if (n >= 1000000000)   return intToString(n/1000000000) + " Billion" + intToString(n%1000000000);
        else if (n >= 1000000) return intToString(n/1000000) + " Million" + intToString(n%1000000);
        else if (n >= 1000)    return intToString(n/1000) + " Thousand" + intToString(n%1000);
        else if (n >= 100)     return intToString(n/100) + " Hundred" + intToString(n%100);
        else if (n >= 20)      return string(" ") + below_100[n/10 - 2] + intToString(n%10);
        else if (n >= 1)       return string(" ") + below_20[n - 1];
        else return "";
    }
};