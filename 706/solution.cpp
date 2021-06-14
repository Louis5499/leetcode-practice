class MyHashMap {
public:
    const size_t n = 1000;
    vector<vector<pair<int, int>>> hash;
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(n);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashedKey = key%n;
        vector<pair<int, int>> &list = hash[hashedKey];
        if (list.size() > 0) {
            for (auto &item: list) {
                if (item.first == key) {
                    item.second = value;
                    return;
                }
            }
        }
        list.emplace_back(pair<int, int>{ key, value });
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashedKey = key%n;
        vector<pair<int, int>> &list = hash[hashedKey];
        if (list.size() > 0) {
            for (auto &item: list) {
                if (item.first == key) {
                    return item.second;
                }
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashedKey = key%n;
        vector<pair<int, int>> &list = hash[hashedKey];
        if (list.size() > 0) {
            for (auto &item: list) {
                if (item.first == key) {
                    item.second = -1;
                    return;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */