class FrontMiddleBackQueue {
public:
    deque<int> a, b;
    void a2b() {
        if (a.size() <= b.size()) return;
        b.push_front(a.back());
        a.pop_back();
    }
    void b2a() {
        if (b.size() <= a.size() + 1) return;
        a.push_back(b.front());
        b.pop_front();
    }

    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        a.push_front(val);
        a2b();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    
    int popFront() {
        if (a.empty() && b.empty()) return -1;
        int ans;
        if (a.empty()) {
            ans = b.front();
            b.pop_front();
        } else {
            ans = a.front();
            a.pop_front();
            b2a();
        }
        return ans;
    }
    
    int popMiddle() {
        if (a.empty() && b.empty()) return -1;
        int res = 0;
        if (b.size() > a.size()) {
            res = b.front();
            b.pop_front();
            // a2b();
        } else {
            res = a.back();
            a.pop_back();
            // b2a();
        }
        return res;
    }
    
    int popBack() {
        if (a.empty() && b.empty()) return -1;
        int res = b.back();
        b.pop_back();
        a2b();
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */