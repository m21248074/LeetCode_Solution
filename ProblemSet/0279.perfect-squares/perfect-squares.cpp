class Solution {
public:
    int numSquares(int n) {
        while(!(n%4)) n/=4;
        if(n%8==7) return 4;
        for(int i=0;i*i<=n;i++)
        {
            int b=sqrt(n-i*i);
            if(i*i+b*b==n) return !!i+!!b;
        }
        return 3;
    }
};