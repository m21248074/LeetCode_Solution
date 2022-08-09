class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result=0;
        while(n)
        {
            if(1&n)
                result++;
            n>>=1;
        }
        return result;
    }
};