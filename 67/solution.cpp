class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1, carryOn = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carryOn > 0) {
            int x = i >= 0 ? a[i--]-'0' : 0;
            int y = j >= 0 ? b[j--]-'0' : 0;
            ans += to_string((x + y + carryOn)%2);
            carryOn = (x + y + carryOn)/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};