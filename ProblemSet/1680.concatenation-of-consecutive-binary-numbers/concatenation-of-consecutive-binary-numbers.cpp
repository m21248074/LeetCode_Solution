class Solution {
public:
    int concatenatedBinary(int n) {
        long result=0,length=0;
        for(int i=1;i<=n;i++)
        {
            if(!(i&i-1)) length++;
            result=((result<<length)+i)%(int(1e9)+7);
        }
        return result;
    }
};