class LRUCache {
public:
    size_t size;
    unordered_map<int, list<pair<int, int>>::iterator> valueMap;
    list<pair<int, int>> valueList;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        auto it = valueMap.find(key);
        if (it == valueMap.end()) {
            return -1;
        }
        valueList.splice(valueList.begin(), valueList, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = valueMap.find(key);
        if (it != valueMap.end()) {
            valueList.splice(valueList.begin(), valueList, it->second);
            it->second->second = value;
            return;
        }
        if (valueList.size() == size) {
            int deletedKey = valueList.back().first;
            valueMap.erase(deletedKey);
            valueList.pop_back();
        }
        valueList.emplace_front(key, value);
        valueMap[key] = valueList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */