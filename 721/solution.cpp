class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> unions;
        // a b c // now b, c have parent a
        // d e f // now e, f have parent d
        // g a d // now abc, def all merged to group g
        
        // a->a
        // b->a
        // c->a
        for (int i=0; i<accounts.size(); i++) {
            for (int j=1; j<accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        // g->g
        // a->g
        // d->g
        for (int i=0; i<accounts.size(); i++) {
            string p = findParent(accounts[i][1], parent);
            for (int j=2; j<accounts[i].size(); j++) {
                parent[findParent(accounts[i][j], parent)] = p;
            }
        }
        
        for (int i=0; i<accounts.size(); i++) {
            for (int j=1; j<accounts[i].size(); j++) {
                unions[findParent(accounts[i][j], parent)].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for (const auto &p: unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            result.emplace_back(emails);
        }
        return result;
    }
    
    // Path compression
    string findParent(string s, unordered_map<string, string> &parent) {
        if (parent[s] != s) {
            parent[s] = findParent(parent[s], parent);
        }
        return parent[s];
    }
};