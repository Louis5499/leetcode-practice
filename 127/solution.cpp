class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        queue<string> todos;
        todos.push(beginWord);
        int ladder = 1;
        while (!todos.empty()) {
            int todoSize = todos.size();
            while (todoSize--) {
                string word = todos.front(); todos.pop();
                if (word == endWord) return ladder;
                wordSet.erase(word);
                for (int i=0; i<word.length(); i++) {
                    char originalChar = word[i];
                    for (int j=0; j<26; j++) {
                        char alpha = j+'a';
                        word[i] = alpha;
                        if (wordSet.find(word) != wordSet.end()) todos.push(word);
                    }
                    word[i] = originalChar;
                }    
            }
            ladder++;
        }
        return 0;
    }
};