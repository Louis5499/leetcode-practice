class Solution {
public:
    bool isRobotBounded(string instructions) {
        int cur[2] = {0, 0};
        int pos[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
        int posI = 0;
        for (char c: instructions) {
            if (c == 'G') {
                cur[0] += pos[posI][0];
                cur[1] += pos[posI][1];
            }
            else if (c == 'L') {
                posI = posI == 0 ? 3 : posI-1;
            } else {
                posI = (posI+1)%4;
            }
        }
        return (cur[0] == 0 && cur[1] == 0) || posI > 0;
    }
};