class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> m;
        for (int i=0; i<order.length(); i++) {
            m[order[i]-'a'] = i;
        }
        
        for (string &word: words) {
            for (char &c: word) {
                c = m[c-'a'];
            }
        }
        
        return is_sorted(words.begin(), words.end());
    }
};