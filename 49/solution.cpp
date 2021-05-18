class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mapping;
        for (auto s: strs) {
            string hashed = hashAnagram(s);
            mapping[hashed].push_back(s);
        }
        
        for (auto set: mapping) {
            ans.emplace_back(set.second);
        }
        return ans;
    }
    
    string hashAnagram(string s) {
        vector<int> count(26, 0);
        for (auto c: s) {
            count[c - 'a']++;
        }
        string output = "";
        for (int i=0; i<26; i++) {
            output += string(count[i], i + 'a');
        }
        return output;
    }
};