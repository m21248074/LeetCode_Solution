class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int mirrorReflection(int p, int q) {
        int t=gcd(p,q);
        p/=t;
        q/=t;
        bool P=p%2==1;
        bool Q=q%2==1;
        if(P&&!Q) return 0;
        else if(P&&Q) return 1;
        return 2;
    }
};