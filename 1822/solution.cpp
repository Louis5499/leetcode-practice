class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for (int num: nums) {
            if (num < 0) product *= -1;
            else if (num > 0) product *= 1;
            else return 0;
        }
        if (product > 0) return 1;
        else return -1;
    }
};