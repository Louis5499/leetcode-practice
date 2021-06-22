class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int n=0, ret = -1, len = _nums.size();
        for (int i=0; i<len; i++) {
            if (_nums[i] != target) continue;
            n++;
            if (rand() % n == 0) ret = i; 
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */