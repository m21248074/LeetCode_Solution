class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double a = double (30*hour) - double(5.5*minutes);
        return min(abs(a),abs(360-abs(a)));
    }
};