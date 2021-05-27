class Solution {
public:
    int getSum(int num) {
        int res = 0;
        while (num > 0) {
            int digit = num%10;
            res += pow(digit, 2);
            num /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
            if (fast == 1) return true;
        } while (slow != fast);
        if (slow == 1) return true;
        return false;
    }
};