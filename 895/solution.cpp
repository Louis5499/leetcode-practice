class FreqStack {
public:
    unordered_map<int, stack<int>> stk;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    FreqStack() {}
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        stk[freq[val]].push(val);
    }
    
    int pop() {
        int val = stk[maxFreq].top(); stk[maxFreq].pop();
        freq[val]--;
        if (stk[maxFreq].size() == 0)  maxFreq--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */