class FirstUnique {
public:
    queue<int> q;
    unordered_map<int, int> counts;
    FirstUnique(vector<int>& nums) {
        for (int num: nums) {
            q.push(num);
            counts[num]++;
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && counts[q.front()] > 1) q.pop();
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        q.push(value);
        counts[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */