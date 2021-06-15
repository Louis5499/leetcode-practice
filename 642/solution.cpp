class AutocompleteSystem {
    struct TrieNode {
        map<char, TrieNode*> next;
        pair<string, int> p;
        TrieNode() {}
    };
    class Trie {
        TrieNode *root;
        
        struct Comp {
            bool operator() (pair<string, int> a, pair<string, int> b) {
                return a.second > b.second || a.second == b.second && a.first < b.first;
            }
        };
            
        void dfs(TrieNode *run, priority_queue<pair<string, int>, vector<pair<string, int>>, Comp>& q) {
            if (run->p.first != "") {
                q.push(run->p);
                if (q.size() > 3) q.pop();
            }
            for (auto next : run->next) {
                dfs(next.second, q);
            }
        }        
    public:
        Trie() {
            root = new TrieNode;
        }
            
        void insert(string s, int times) {
            TrieNode* run = root;
            for (auto c : s) {
                if (!run->next[c]) {
                    run->next[c] = new TrieNode;
                }
                run = run->next[c];
            }
            run->p.first = s;
            run->p.second += times;
        }
        
        vector<string> search(string s) {
            TrieNode* run = root;
            for (int i = 0; i < s.size(); i++) {
                if (!run) return {};
                run = run->next[s[i]];
            }
            if (!run) return {};
            priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> q;                 
            dfs(run, q);
            vector<string> res;
            while (!q.empty()) {
                res.push_back(q.top().first);
                q.pop();
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };
    Trie trie;
    string s = "";
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        for (int i = 0; i < sentences.size(); i++) 
            trie.insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie.insert(s, 1);
            s.clear();
            return {};
        }
        s += c;
        return trie.search(s);
    }
};