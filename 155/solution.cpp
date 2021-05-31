class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= getMin()) minStk.push(val);
    }
    
    void pop() {
        if (stk.top() == getMin()) minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */