class MyCircularQueue {
private:
    vector<int> dq;
    int size = 0, front = 0, back = -1, curSize = 0;
public:
    MyCircularQueue(int k) {
        dq = vector<int>(k, 0);
        size = k;
    }
    
    bool enQueue(int value) {
        if (curSize >= size) return false;
        back = (back+1)%size;
        dq[back] = value;
        curSize++;
        return true;
    }
    
    bool deQueue() {
        if (curSize == 0) return false;
        front = (front+1)%size;
        curSize--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : dq[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : dq[back];
    }
    
    bool isEmpty() {
        return curSize == 0;
    }
    
    bool isFull() {
        return curSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */