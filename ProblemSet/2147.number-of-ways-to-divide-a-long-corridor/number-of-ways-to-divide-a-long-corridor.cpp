class Solution {
public:
    int numberOfWays(string corridor) {
        int mod=1e9+7;
        int seatCnt=0;
        int last=-1;
        long result=1;
        int n=corridor.size();
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='P')
                continue;
            seatCnt+=1;
            if(seatCnt>=2&&seatCnt%2)
            {
                result*=(i-last);
                result%=mod;
            }
            last=i;
        }
        if(seatCnt>=2&&seatCnt%2==0)
            return (int)result;
        return 0;
    }
};