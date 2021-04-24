class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums(n, 0);
        for (int i=0; i<n; i++) {
            nums[i] = i + 1;
        }
        
        int remaining = n, cursor = 0;
        
        while (remaining > 1) {
            cursor = (cursor + k - 1) % remaining;
            nums.erase(nums.begin() + cursor);
            remaining--;
        }
        
        return nums[0];
    }
};