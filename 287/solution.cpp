class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // According the Floyd's Cycle Detection Algo
        if (nums.size() <= 1) return -1;

        // Find intersection
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // Find entry point
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};