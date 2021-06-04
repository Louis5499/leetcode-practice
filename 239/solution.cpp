class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vals(n-k+1, 0);
        int ri = 0;
        deque<int> q;
        for (int i=0; i<n; i++) {
            while(!q.empty() && q.front() < i-k+1) q.pop_front(); // Dequeue front elements
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k-1) vals[ri++] = nums[q.front()];
        }
        return vals;
    }
};