class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num: nums) count[num]++;
        
        for (auto record: count) {
            minHeap.push(record.second);
            
            if (minHeap.size() > k) minHeap.pop();
        }
        
        vector<int> res;
        for (auto record: count) {
            if (record.second >= minHeap.top()) res.emplace_back(record.first);
        }
        return res;
    }
};