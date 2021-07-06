class BoundedBlockingQueue {
private:
    mutex m_queue_mutex;
    condition_variable m_queue_changed;
    queue<int> m_queue; // m_queue_mutex
    int m_capacity; // m_queue_mutex
public:
    BoundedBlockingQueue(int capacity) {
        m_capacity = capacity;
    }
    
    void enqueue(int element) {
        {
            unique_lock<mutex> lk(m_queue_mutex);
            m_queue_changed.wait(lk, [this]{ return m_queue.size() < m_capacity; });
            m_queue.push(element);
        }
        m_queue_changed.notify_one();
    }
    
    int dequeue() {
        int ret = 0;
        {
            unique_lock<mutex> lk(m_queue_mutex);
            m_queue_changed.wait(lk, [this]{ return m_queue.size() > 0; });
            ret = m_queue.front(); m_queue.pop();
        }
        m_queue_changed.notify_one();
        return ret;
    }
    
    int size() {
        unique_lock<mutex> lk(m_queue_mutex);
        return m_queue.size();
    }
};