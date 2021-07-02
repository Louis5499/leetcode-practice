class Solution {
public:
    int fib(int n) {
        int prev = 0, now = 1;
        if (n == 0) return 0;
        else if (n == 1) return 1;
        n--;
        while (n--) {
            int tmp = now;
            now += prev;
            prev = tmp;
        }
        return now;
    }
};