class OrderedStream {
public:
    map<int, string> m;
    int idx = 1;
    OrderedStream(int n) {}
    
    vector<string> insert(int idKey, string value) {
        m[idKey] = value;
        vector<string> output;
        while (m.count(idx)) output.push_back(m[idx++]);
        return output;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */