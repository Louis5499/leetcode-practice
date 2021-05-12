class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n+1, 0);
        steps[0] = 0;
        steps[1] = 1;
        if (n < 2) return steps[n];
        steps[2] = 2;
        for (int i=3; i<=n;i++) {
            steps[i] = (steps[i-2] + steps[i-1]);
        }
        return steps[n];
    }
};