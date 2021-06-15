class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto &s: arr) {
            bitset<26> bits;
            for (char c: s) bits.set(c-'a');
            int n = bits.count();
            if (n < s.length()) continue; // Word has duplicate chars
            
            for (int i=dp.size()-1; i>=0; i--) {
                bitset oldBits = dp[i];
                if ((oldBits&bits).any()) continue;
                dp.push_back(oldBits | bits);
                res = max(res, n + (int)oldBits.count());
            }
        }
        return res;
    }
};