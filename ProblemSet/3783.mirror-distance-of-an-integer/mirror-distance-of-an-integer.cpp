class Solution {
public:
    int reverse(int n) {
        int result=0;
        while(n>0)
        {
            result=result*10+n%10;
            n/=10;
        }
        return result;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};