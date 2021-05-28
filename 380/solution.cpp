class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> pool;
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            pool.emplace_back(val);
            m[val] = pool.size()-1;
            return true;
        }
        else return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (it != m.end()) {
            int last = pool.back();
            m[last] = m[val];
            pool[m[val]] = last;
            pool.pop_back();
            m.erase(it);
            return true;
        }
        else return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return pool[rand()%pool.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */