class CustomStack {
public:
    int n;
    vector<int> stk, inc;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < n) {
            stk.emplace_back(x);
            inc.emplace_back(0);
        }
    }
    
    int pop() {
        int i = stk.size()-1;
        if (i < 0) return -1;
        if (i > 0) inc[i-1] += inc[i];
        int res = stk[i] + inc[i];
        stk.pop_back();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int minVal = min(k, (int)stk.size()) - 1;
        if (minVal >= 0) inc[minVal] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */