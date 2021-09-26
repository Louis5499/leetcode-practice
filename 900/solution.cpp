class RLEIterator {
public:
    vector<int> storage;
    int encodingIdx = 0;
    RLEIterator(vector<int>& encoding) {
        storage = encoding;
    }
    
    int next(int n) {
        int size = storage.size();
        while (encodingIdx < size && n > storage[encodingIdx]) {
            n -= storage[encodingIdx];
            encodingIdx += 2;
        }
        
        if (encodingIdx < size) storage[encodingIdx] -= n;
        
        return encodingIdx < size ? storage[encodingIdx+1] : -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */