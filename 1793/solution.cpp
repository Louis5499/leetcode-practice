class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int score = nums[k];
        int left = k, right = k;
        int minimun = nums[k];
        while(left > 0 || right < nums.size() - 1) {
            if (left > 0 && right < nums.size() - 1) {
                if (nums[left-1] > nums[right+1]) {
                    left--;
                } else if (nums[left-1] < nums[right+1]) {
                    right++;
                } else {
                    left--;
                    right++;
                }
            } else if (left > 0) {
                left--;
            } else if (right < nums.size() - 1) {
                right++;
            } else {
                break;
            }
            minimun = min(minimun, min(nums[left], nums[right]));
            score = max(score, minimun*(right-left+1));
        }
        return score;
    }
};