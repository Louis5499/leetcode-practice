/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Compare {
    public:
        bool operator() (Interval a, Interval b) {
            return a.start > b.start;
        }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> result;
        priority_queue<Interval, vector<Interval>, Compare> pq;
        
        for (auto person: schedule) {
            for (Interval interval: person)  pq.push(interval);
        }
        
        Interval tmp = pq.top(); pq.pop();
        while (!pq.empty()) {
            if (tmp.end < pq.top().start) {
                result.emplace_back(tmp.end, pq.top().start);
                tmp = pq.top(); pq.pop();
            } else {
                tmp = tmp.end < pq.top().end ? pq.top() : tmp;
                pq.pop();
            }
        }
        return result;
    }
};