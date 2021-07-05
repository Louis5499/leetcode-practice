class AllOne {
public:
    /** Initialize your data structure here. */
    map<int,list<string>> countMap;   // count -> list of keys
    unordered_map<string,list<string>::iterator> kv;   // key -> iterator in countMap
    unordered_map<string,int> count;  // key -> current count
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!count[key]){
            countMap[1].push_back(key);
            kv[key] = prev(countMap[1].end());
            count[key] = 1;
        }else{
            update(key,count[key],count[key]+1);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!count[key])
            return;
        update(key,count[key],count[key]-1);
    }
    
    void update(string key, int oldC, int newC){
        count[key] = newC;
        auto it = kv[key];
        countMap[oldC].erase(it);
        if(countMap[oldC].size()==0)
            countMap.erase(oldC);
        if(newC > 0){
            countMap[newC].push_back(key);
            kv[key] = prev(countMap[newC].end());
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(countMap.empty())
            return "";
        return *(countMap.rbegin()->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(countMap.empty())
            return "";
        return *(countMap.begin()->second.begin());
    }
};