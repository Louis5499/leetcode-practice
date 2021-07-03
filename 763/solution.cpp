class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> pos(26, 0);
        for (int i=0; i<s.length(); i++) pos[s[i] - 'a'] = i;
        
        vector<int> output;
        int start = 0, last = 0;
        for (int i=0; i<s.length(); i++) {
            last = max(last, pos[s[i]-'a']);
            if (last == i) {
                output.emplace_back(last-start+1);
                start = last+1;
            }
        }
        return output;
    }
};