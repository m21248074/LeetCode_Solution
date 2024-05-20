class Solution {
public:
    int pivotInteger(int n) {
        int sum=(1+n)*n/2;
        int preSum=0;
        for(int i=1;i<=n;i++)
        {
            preSum+=i;
            if(preSum==sum-preSum+i)
                return i;
        }
        return -1;
    }
};