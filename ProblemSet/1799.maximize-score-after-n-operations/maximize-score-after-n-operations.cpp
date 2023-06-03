class Solution {
public:
    int gcd(int x,int y)
    {
        if(!y)
            return x;
        return gcd(y,x%y);
    }
    int count(int x)
    {
        int result=0;
        while(x>0)
        {
            x=x&(x-1);
            result++;
        }
        return result;
    }
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> gcdNums(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                gcdNums[i][j]=gcd(nums[i],nums[j]);
        }
        int range=1<<n;
        vector<int> dp(range,0);
        for(int i=0;i<range;i++)
        {
            int temp=count(i);
            if((temp&1)==1)
                continue;
            for(int j=0;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    int state=(1<<j)|(1<<k);
                    if((state&i)!=state)
                        continue;
                    dp[i]=max(dp[i],dp[i-state]+gcdNums[j][k]*(temp>>1));
                }
            }
        }
        return dp[range-1];
    }
};