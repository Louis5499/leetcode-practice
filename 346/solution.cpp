class MovingAverage {
public:
    /** Initialize your data structure here. */
    int size = 0;
    int sum = 0;
    int count = 0;
    queue<int> q;
    MovingAverage(int _size) {
        size = _size;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (++count > size) {
            count = size;
            sum -= q.front();
            q.pop();
        }
        return (double) sum / count;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */