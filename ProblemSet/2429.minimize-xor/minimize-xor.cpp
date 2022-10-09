class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if(num1==num2) return num1;
        int n=__builtin_popcount(num2);
        int result=0;
        // for(int i=31;i>=0;i--)
        // {
        //     int cur=(num1>>i)&1;
        //     if(cur&&n>0)
        //     {
        //         result|=(1<<i);
        //         n--;
        //     }
        // }
        for(int i=0;i<32;i++)
        {
            int cur=(num1>>i)&1;
            if(cur&&n>0)
            {
                result|=(1<<i);
                n--;
            }
        }
        for(int i=0;i<32;i++)
        {
            if(!n) break;
            int cur=(result>>i)&1;
            if(!cur)
            {
                result|=(1<<i);
                n--;
            }
        }
        return result;
    }
};