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

class Trie {
public:
    TrieNode *root = NULL;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (char c: word) {
            node = node->findOrInsertChildren(c);
        }
        node->isEnd = true;
    }
    
    TrieNode* searchPrefix(string s) {
        TrieNode *node = root;
        for (char c:s) {
            if (node->childrens[c - 'a'] != NULL) node = node->childrens[c - 'a'];
            else return NULL;
        }
        return node;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *result = searchPrefix(word);
        return result != NULL && result->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *result = searchPrefix(prefix);
        return result != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */