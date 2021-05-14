class Solution {
public:
    string alienOrder(vector<string>& words) {
        // 0. Initialize the alphabets dictionary
        map<char, vector<char>> adjList;
        map<char, int> counts; // memorized the connected times
        for (string word: words) {
            for (char c: word) {
                counts[c] = 0;
                adjList[c] = {};
            }
        }
        
        // 1. Find edges
        for (int i=0; i<words.size()-1; i++) {
            string word1 = words[i];
            string word2 = words[i+1];
            
            if (word2.length() < word1.length() && word1.rfind(word2, 0) == 0) {
                // Check whether word1 is a prefix of word2
                return "";
            }
            
            for (int j=0; j<min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].push_back(word2[j]);
                    counts[word2[j]]++;
                    break;
                }
            }
        }
        
        // 2. BFS
        queue<char> q;
        string ans = "";
        for (auto const& [key, val]: counts) {
            if (val == 0) {
                q.push(key);
            }
        }
        
        while(!q.empty()) {
            char candidate = q.front();
            q.pop();
            ans += candidate;
            for (char nextChar: adjList[candidate]) {
                if (--counts[nextChar] == 0) {
                    q.push(nextChar);
                }
            }
            
        }
        
        if (ans.length() < counts.size()) {
            return "";
        }
        
        return ans;
    }
};