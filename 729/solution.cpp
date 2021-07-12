class MyCalendar {
private:
    map<int, int> intervals;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = intervals.lower_bound(start);
        if (it != intervals.end() && end > it->first) return false;
        if (it != intervals.begin() && start < (--it)->second) return false;
        intervals[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */