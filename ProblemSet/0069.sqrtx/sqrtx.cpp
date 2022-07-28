class Solution {
public:
    long f(long x)
    {
        return x*x;
    }
    int mySqrt(int x) {
        int l=1,r=x;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(f(m)>x)
                r=m-1;
            else if(f(m)<x)
                l=m+1;
            else // f(x)==x
                return m;
        }
        return l-1;
    }
};