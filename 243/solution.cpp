class Solution {
public:
   int shortestDistance(vector<string>& words, string word1, string word2) {
        int i = -1, j = -1, n = words.size(), dist = INT_MAX;
        for (int k = 0; k < n; k++) {
            if (words[k] == word1) {
                i = k;
            } else if (words[k] == word2) {
                j = k;
            }
            if (i >= 0 && j >= 0) {
                dist = min(dist, abs(i - j));
            }
        }
        return dist;
    }
};