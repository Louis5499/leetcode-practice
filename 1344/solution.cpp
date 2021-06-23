class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle1 = hour*30 + (double)minutes/2;
        double angle2 = minutes*6;
        double minAngle = abs(angle1 - angle2);
        minAngle = min(minAngle, 360 - minAngle);
        return minAngle;
    }
};