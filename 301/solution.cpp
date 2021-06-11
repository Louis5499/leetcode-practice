class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        char braces[2] = { '(', ')' };
        dfs(s, 0, 0, braces, res);
        return res;
    }
    
    void dfs(string s, int lastI, int lastJ, char *braces, vector<string> &res) {
        int count = 0;
        int i = lastI;
        while (i < s.length() && count >= 0) {
            if (s[i] == braces[0]) count++;
            else if (s[i] == braces[1]) count--;
            i++;
        }
        
        // Finish checking ')', turn to '('
        if (count >= 0) {
            reverse(s.begin(), s.end());
            char newBraces[2] = { ')', '(' };
            if (braces[0] == '(') dfs(s, 0, 0, newBraces, res);
            else res.emplace_back(s);
        }
        else {
            // Process to delete redundant ')'
            i-=1; // last redundant i;
            for (int j = lastJ; j <= i; j++) {
                if (s[j] == braces[1] && (j == lastJ || s[j-1] != braces[1])) {
                    dfs(s.substr(0, j) + s.substr(j+1, s.length()), i, j, braces, res); 
                }
            }
        }
    }
};