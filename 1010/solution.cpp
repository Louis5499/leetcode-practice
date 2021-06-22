class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> pool(60, 0);
        int res = 0;
        for (int perTime: time) {
            res += pool[(600-perTime) % 60];
            pool[perTime%60]++;
        }
        return res;
    }
};