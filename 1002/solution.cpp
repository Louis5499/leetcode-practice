class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> alphas(26, INT_MAX);
        for (string word: words) {
            vector<int> innerAlphas(26, 0);
            for (char c: word) innerAlphas[c-'a']++;
            for (int i=0; i<26; i++) alphas[i] = min(alphas[i], innerAlphas[i]);
        }
        
        vector<string> output;
        for (int i=0; i<26; i++) {
            for (int j=0; j<alphas[i]; j++) output.emplace_back(string(1, i+'a'));
        }
        return output;
    }
};