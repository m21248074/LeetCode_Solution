class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n&&!(n%4))
        {
            n/=4;
        }
        return n==1;
    }
};