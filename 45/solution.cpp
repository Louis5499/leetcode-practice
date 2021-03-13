class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int step = 0;
        int iL = 0, iR = 0;
        while (iR < n - 1) {
            int nextIR = 0;
            for (int i=iL; i<=iR; i++) {
                nextIR = max(nextIR, i + nums[i]);
            }
            iL = iR + 1;
            iR = nextIR;
            step++;
        }
        return step;
    }
};