class Solution {
public:
    int climbStairs(int n) {
        int prev = 2, prevBeforePrev = 1, now = 1;
        if (n == 1) return 1;
        else if (n == 2) return 2;
        for (int i=3; i<=n;i++) {
            now = (prev + prevBeforePrev);
            prevBeforePrev = prev;
            prev = now;
        }
        return now;
    }
};