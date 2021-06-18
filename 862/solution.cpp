class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), j = 0, leng = n+1;
        deque<int> dq;
        for (int i=0; i<n; i++) {
            if (i > 0) {
                nums[i] += nums[i-1];
            }
            if (nums[i] >= k) {
                leng = min(leng, i+1);
            }
            while (dq.size() > 0 && nums[i] - nums[dq.front()] >= k) {
                leng = min(leng, i - dq.front());
                dq.pop_front();
            }
            while (dq.size() > 0 && nums[i] <= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return leng == n+1 ? -1 : leng;
    }
};