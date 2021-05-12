class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t output = 0;
        int idx = 0;
        while (n > 0) {
            if ((n & 1) == 1) output += 1 << (31 - idx);
            idx++;
            n = n >> 1;
        }
        return output;
    }
};