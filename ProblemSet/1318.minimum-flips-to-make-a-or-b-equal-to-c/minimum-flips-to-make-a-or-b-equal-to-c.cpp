class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result=0;
        while(a>0||b>0||c>0)
        {
            int bitA=a&1;
            int bitB=b&1;
            int bitC=c&1;
            if((bitA|bitB)!=bitC)
            {
                if(bitC==1)
                    result++;
                else // bitC==0
                    result+=(bitA+bitB);
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return result;
    }
};