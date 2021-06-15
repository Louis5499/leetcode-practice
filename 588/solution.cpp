class FileSystem {
private:
    struct TrieNode {
        bool isFile;
        string content;
        unordered_map<string, TrieNode *> children;
        TrieNode() : isFile(false) {}
    };

    TrieNode *root;
public:
    FileSystem() {
       root = new TrieNode(); 
    }
    
    vector<string> getStrs(string &path) {
        vector<string> ans;
        int i = 1, j = 1;
        while (j <= path.length()) {
            if (i != j && (j == path.length() || path[j] == '/')) {
                ans.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        return ans;
    }

    vector<string> ls(string path) {
        vector<string> dirs = getStrs(path);
        TrieNode *cur = root;
        for (string &dir: dirs) {
            cur = cur->children[dir];
        }
        
        if (cur->isFile) {
            return {dirs.back()};
        }
        
        vector<string> output;
        for (auto &it: cur->children) {
            output.emplace_back(it.first);
        }
        sort(output.begin(), output.end());
        return output;
    }
    
    TrieNode* traverse(string path) {
        vector<string> dirs = getStrs(path);
        TrieNode *cur = root;
        for (string &dir: dirs) {
            if (!cur->children.count(dir)) {
                cur->children[dir] = new TrieNode();
            }
            cur = cur->children[dir];
        }
        return cur;
    }

    void mkdir(string path) {
        traverse(path);
    }
    
    void addContentToFile(string filePath, string content) {
        TrieNode* node = traverse(filePath);
        node->isFile = true;
        node->content = node->content.append(content);
    }
    
    string readContentFromFile(string filePath) {
        TrieNode* node = traverse(filePath);
        return node->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */