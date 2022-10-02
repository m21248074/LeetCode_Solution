class Solution {
public:
    int gcd(int a,int b)
    {
        if(!b) return a;
        return gcd(b,a%b);
    }
    int commonFactors(int a, int b) {
        int n=gcd(a,b);
        int result=0;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(!(n%i))
            {
                if(n/i==i)
                    result+=1;
                else
                    result+=2;
            }
        }
        return result;
    }
};