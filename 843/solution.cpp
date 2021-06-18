/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string a, string b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] == b[i]) matches++;
        return matches;
    }

    void findSecretWord(vector<string>& wordlist, Master& master) {
        int count[6][26], x = 0, best;
        for (int t = 0; t < 10 && x < 6; ++t) {
            memset(count, 0, 156 * sizeof(int));
            for (string w : wordlist)
                for (int i = 0; i < 6; ++i)
                    count[i][w[i] - 'a']++;
            best = 0;
            string guess = wordlist[0];
            for (string w: wordlist) {
                int score = 0;
                for (int i = 0; i < 6; ++i)
                    score += count[i][w[i] - 'a'];
                if (score > best) {
                    guess = w;
                    best = score;
                }
            }
            x = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(guess, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
};