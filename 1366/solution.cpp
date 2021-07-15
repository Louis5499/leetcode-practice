class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> counts(26, vector<int>(27));
        for (char &c: votes[0]) {
            counts[c-'A'][26] = c;
        }
        
        for (string& vote: votes)
            for (int i = 0; i < vote.length(); ++i)
                --counts[vote[i]-'A'][i];
        
        sort(counts.begin(), counts.end());
        string res = "";
        for (int i=0; i<votes[0].length(); i++) {
            res += counts[i][26];
        }
        return res;
    }
};