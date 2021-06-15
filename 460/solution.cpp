class LFUCache {
    int cap;
    int size;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToVF; //key -> {value,freq};
    unordered_map<int, list<int>> fToKeys;  //freq -> key list;
    unordered_map<int, list<int>::iterator> keyToIter; //key -> above list iterator;
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        minFreq = 1;
    }
    
    int get(int key) {
        if (keyToVF.count(key) == 0) return -1;
        
        fToKeys[keyToVF[key].second].erase(keyToIter[key]);
        keyToVF[key].second++;
        fToKeys[keyToVF[key].second].emplace_back(key);
        keyToIter[key] = --fToKeys[keyToVF[key].second].end();
        
        if (fToKeys[minFreq].size() == 0) minFreq++;
        
        return keyToVF[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        
        int storedVal = get(key);
        if (storedVal != -1) {
            keyToVF[key].first = value;
            return;
        }
        
        if (size >= cap) {
            keyToVF.erase(fToKeys[minFreq].front());
            keyToIter.erase(fToKeys[minFreq].front());
            fToKeys[minFreq].pop_front();
            size--;
        }
        
        keyToVF[key] = {value, 1};
        fToKeys[1].push_back(key);
        keyToIter[key] = --fToKeys[1].end();
        minFreq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */