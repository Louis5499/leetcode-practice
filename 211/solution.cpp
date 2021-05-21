class TrieNode {
public:
    bool isEnd;
    TrieNode** childrens;
    TrieNode() {
        childrens = new TrieNode*[26]();
        isEnd = false;
    }
    
    TrieNode* findOrInsertChildren(char c) {
        if (childrens[c - 'a'] == NULL) {
            childrens[c - 'a'] = new TrieNode();
        }
        return childrens[c - 'a'];
    }
};

class WordDictionary {
public:
    TrieNode *root = NULL;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for (char c: word) {
            node = node->findOrInsertChildren(c);
        }
        node->isEnd = true;
    }
    
    bool recurSearch(TrieNode * node, string &word, int offset) {
        if (offset == word.length()) return node->isEnd == true;
        char c = word[offset];
        if (c == '.') {
            for (int i=0; i<26; i++) {
                if (node->childrens[i] != NULL && recurSearch(node->childrens[i], word, offset+1)) return true;
            }
        }
        else if (node->childrens[c - 'a'] != NULL) return recurSearch(node->childrens[c - 'a'], word, offset+1);
        return false;
    }
    
    bool search(string word) {
        return recurSearch(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */