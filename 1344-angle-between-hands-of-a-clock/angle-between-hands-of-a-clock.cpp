class Solution {
public:
    double angleClock(int hour, int minute) {
        double angle = abs((30 * (hour % 12) + 0.5 * minute) - 6 * minute);
        angle = min(angle, 360 - angle);
        return angle;
    }
};