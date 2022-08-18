class Solution {
public:
    int get1Bits(int n)
    {
        int result=0;
        while(n)
        {
            if(n%2)
                result++;
            n/=2;
        }
        return result;
    }
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        return get1Bits(n)==1;
    }
};