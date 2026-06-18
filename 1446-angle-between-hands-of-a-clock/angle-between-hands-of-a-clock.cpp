class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12 ;
        double dmin =  2.0 * minutes / 60 ;
        double dhour = 2.0 * minutes / (60 * 12) ;
        dhour += 1.0 * hour / 6;

        dhour *= 180;
        dmin *= 180 ;

        double angle = abs(dmin - dhour)   ;

        return min(360 - angle, angle) ;
    }
};