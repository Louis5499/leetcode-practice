class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int maxNum = releaseTimes[0];
        int maxIdx = 0;
        for (int i=1; i<releaseTimes.size(); i++) {
            if (releaseTimes[i] - releaseTimes[i-1] > maxNum) {
                maxNum = releaseTimes[i] - releaseTimes[i-1];
                maxIdx = i;
            } else if (releaseTimes[i] - releaseTimes[i-1] == maxNum) {
                maxIdx = keysPressed[i] > keysPressed[maxIdx] ? i : maxIdx;
            }
        }
        return keysPressed[maxIdx];
    }
};