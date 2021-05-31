class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        if (s.length() == 0) return output;

        vector<string> paths;        
        dfs(0, s, paths, output);
        
        return output;
    }
    
    void dfs(int left, string s, vector<string> &paths, vector<vector<string>> & output) {
        if (left == s.length()) {
            output.push_back(paths);
            return;
        }
        for (int i=left; i<s.length(); i++) {
            if(isPalindrome(s, left, i)) {
                paths.push_back(s.substr(left, i-left+1));
                dfs(i+1, s, paths, output);
                paths.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int left, int right) {
        if (left >= right) return true;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};