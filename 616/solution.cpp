class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<bool> label(s.length(), false);
        for (string &word: words) {
            int idx = 0;
            auto found = s.find(word, idx);
            while (found != string::npos) {
                for (int i=found; i<found+word.length(); i++) label[i] = true;
                idx = found + 1;
                found = s.find(word, idx);
            }
        }
        
        bool opened = false;
        string output = "";
        for (int i=0; i<s.length(); i++) {
            if (label[i] && !opened) {
                output += "<b>";
                opened = true;
            }
            else if (!label[i] && opened) {
                output += "</b>";
                opened = false;
            }
            output += s[i];
        }
        if (opened) output += "</b>";
        return output;
    }
};