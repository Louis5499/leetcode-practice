class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> counts(10, 0);
        for (char c: secret) {
            counts[c-'0']++;
        }

        int a=0, b=0;
        for (int i=0; i<guess.size(); i++) {
            if (secret[i] == guess[i]) {
                a++;
                if (counts[secret[i]-'0']-- <= 0) b--;
            } else if (counts[guess[i]-'0'] > 0) {
                counts[guess[i]-'0']--;
                b++;
            }
        }
        
        string output = to_string(a) + "A" + to_string(b) + "B";
        return output;
    }
};