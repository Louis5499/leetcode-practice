class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;

    MaxStack() {}
    
    void push(int x) {
        v.insert(v.begin(), x);
        mp[x].push_back(v.begin());
    }
    
    int pop() {
        int it = *v.begin();
        mp[it].pop_back();
        if (mp[it].empty()) mp.erase(it);
        v.erase(v.begin());
        return it;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int num = mp.rbegin()->first;
        auto it = mp[num].back();
        mp[num].pop_back();
        if (mp[num].empty()) mp.erase(num);
        v.erase(it);
        return num;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */