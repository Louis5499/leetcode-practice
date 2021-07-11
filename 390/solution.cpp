class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool dir = true;
        while (n > 1) {
            if (dir) head += step;
            else head += n%2 ? step : 0;
            
            n /= 2;
            step *= 2;
            dir = !dir;
        }
        return head;
    }
};