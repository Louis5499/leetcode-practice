class Solution {
public:
    string convertToTitle(int columnNumber) {
        string output = "";
        while (columnNumber) {
            columnNumber--;
            output += (columnNumber%26) + 'A';
            columnNumber /= 26;
        }
        reverse(output.begin(), output.end());
        return output;
    }
};