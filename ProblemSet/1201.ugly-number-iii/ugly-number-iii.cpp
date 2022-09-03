class Solution {
public:
    long gcd(long a,long b)
    {
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }
    long lcm(long a,long b)
    {
        return a*b/gcd(a,b);
    }
    long helper(int n,int a,int b,int c)
    {
        long setA=n/a;
        long setB=n/b;
        long setC=n/c;
        long setAB=n/lcm(a,b);
        long setBC=n/lcm(b,c);
        long setAC=n/lcm(a,c);
        long setABC=n/lcm(lcm(a,b),c);
        return setA+setB+setC-setAB-setBC-setAC+setABC;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long left=1,right=2e9;
        while(left<=right)
        {
            long mid=(left+right)/2;
            if(helper(mid,a,b,c)<n)
                left=mid+1;
            else // helper(mid,a,b,c)>=n
                right=mid-1;
        }
        return left;
    }
};