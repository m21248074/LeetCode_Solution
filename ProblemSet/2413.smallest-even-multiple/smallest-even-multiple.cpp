class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int smallestEvenMultiple(int n) {
        return 2*n/gcd(2,n);
    }
};