class Solution {
public:
    string intToRoman(int num) {
        string output = "";
        while (num > 0) {
            if (num/1000) {
                output += 'M';
                num -= 1000;
            }
            else if (num/900) {
                output += "CM";
                num -= 900;
            }
            else if (num/500) {
                output += 'D';
                num -= 500;
            }
            else if (num/400) {
                output += "CD";
                num -= 400;
            }
            else if (num/100) {
                output += 'C';
                num -= 100;
            }
            else if (num/90) {
                output += "XC";
                num -= 90;
            }
            else if (num/50) {
                output += 'L';
                num -= 50;
            }
            else if (num/40) {
                output += "XL";
                num -= 40;
            }
            else if (num/10) {
                output += 'X';
                num -= 10;
            }
            else if (num/9) {
                output += "IX";
                num -= 9;
            }
            else if (num/5) {
                output += 'V';
                num -= 5;
            }
            else if (num/4) {
                output += "IV";
                num -= 4;
            }
            else if (num/1) {
                output += 'I';
                num -= 1;
            }
        }
        return output;
    }
};