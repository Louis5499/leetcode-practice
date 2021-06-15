class WordDistance {
public:
    unordered_map<string, vector<int>> m;
    WordDistance(vector<string>& wordsDict) {
       for (int i=0; i<wordsDict.size(); i++) {
            m[wordsDict[i]].emplace_back(i);   
       }
    }
    
    int shortest(string word1, string word2) {
        int i=0, j=0, distance = INT_MAX;
        while (i < m[word1].size() && j < m[word2].size()) {
            distance = min(distance, abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? i++ : j++;
        }
        return distance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */