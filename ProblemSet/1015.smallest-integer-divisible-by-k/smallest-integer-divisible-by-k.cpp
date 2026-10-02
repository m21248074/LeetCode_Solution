class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int tmp=1%k;
        for(int i=1;i<=k;i++)
        {
            if(tmp%k==0)
                return i;
            tmp=(tmp*10+1)%k;
        }
        return -1;
    }
};