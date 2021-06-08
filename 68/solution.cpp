class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> result;

        for (int i=0; i<n;) {
            int wordWidth = words[i].length();
            int j=i+1;
            while (j < n && (wordWidth + 1 + words[j].length()) <= maxWidth) {
                wordWidth += 1 + words[j].length();
                j++;
            }
            
            string s = words[i];
            if (j != i+1 && j != n) {
                int spaces = (maxWidth - wordWidth)/(j-i-1);
                int extraSpaces = (maxWidth - wordWidth)%(j-i-1);
                for (int k=i+1; k<j; k++) {
                    s += string(spaces + 1 + (k-(i+1) < extraSpaces), ' ') + words[k];
                }
            } else {
                for (int k=i+1; k<j; k++) s += " " + words[k];
                s += string(maxWidth - s.length(), ' ');
            }
            result.emplace_back(s);
            i = j;
        }
        return result;
    }
};