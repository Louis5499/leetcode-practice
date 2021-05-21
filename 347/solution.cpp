class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<int>> maxHeap;
        
        for (int num: nums) count[num]++;
        
        for (auto record: count) {
            maxHeap.push(record.second);
            
            if (maxHeap.size() > k) maxHeap.pop();
        }
        
        vector<int> res;
        for (auto record: count) {
            if (record.second >= maxHeap.top()) res.emplace_back(record.first);
        }
        return res;
    }
};