class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> lowHeap;
    priority_queue<int> highHeap;
    bool isEven = true;
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (isEven) {
            lowHeap.push(num);
            highHeap.push(lowHeap.top());
            lowHeap.pop();
        } else {
            highHeap.push(num);
            lowHeap.push(highHeap.top());
            highHeap.pop();
        }
        isEven = !isEven;
    }
    
    double findMedian() {
        if (isEven) return (double)(lowHeap.top() + highHeap.top()) / 2.0;
        else return (double)highHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */