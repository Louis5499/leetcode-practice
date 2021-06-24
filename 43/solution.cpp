class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> pos(num1.size() + num2.size(), 0);
        for (int i=num1.size()-1; i>=0; i--) {
            for (int j=num2.size()-1; j>=0; j--) {
                int product = (num1[i]-'0')*(num2[j]-'0');
                int p1 = i+j, p2 = i+j+1;
                int sum = pos[p2] + product;
                
                pos[p2] = sum % 10;
                pos[p1] += sum / 10; 
            }
        }
        
        string output = "";
        for (int digit: pos) {
            if (output.length() == 0 && digit == 0) continue;
            output += to_string(digit);
        }
        return output.length() > 0 ? output: "0";
    }
};