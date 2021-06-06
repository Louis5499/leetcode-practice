class Solution {
public:
    int binaryGap(int n) {
        int rightIdx = -1, maxLen = 0;
        for (int i=0; n>0; i++) {
            if (n & 1) {
                if (rightIdx == -1) rightIdx = i;
                else {
                    maxLen = max(maxLen, i - rightIdx);
                    rightIdx = i;
                }
            }
            n>>=1;
        }
        return maxLen;
    }
};