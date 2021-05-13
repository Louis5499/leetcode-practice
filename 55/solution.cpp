class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxDes = 0;
        for (int i=0; i<n && i<=maxDes; i++) {
            maxDes = max(maxDes, i+nums[i]);
        }
        return (maxDes >= n-1);
    }
};