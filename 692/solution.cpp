class Compare {
    public:
        bool operator() (pair<int, string> a, pair<int, string> b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        map<string, int> count;
        
        for (string &word: words) {
            count[word]++;
        }
        
        for (auto perCount: count) {
            pq.push(make_pair(perCount.second, perCount.first));
            if (pq.size() > k) pq.pop();
        }
        
        vector<string> result;
        while (k--) {
            result.insert(result.begin(), pq.top().second);
            pq.pop();
        }
        return result;
    }
};