class Solution {
public:
    int helper(int n,vector<int> &dp,int &result)
    {
        if(dp[n]==-1)
        {
            if(!(n%2))
                dp[n]=helper(n>>1,dp,result);
            else
                dp[n]=helper(n/2,dp,result)+helper(n/2+1,dp,result);
        }
        result=max(result,dp[n]);
        return dp[n];
    }
    int getMaximumGenerated(int n) {
        vector<int> dp(n+2,-1);
        int result=INT_MIN;
        dp[0]=0;
        dp[1]=1;
        for(int i=0;i<=n;i++)
            helper(i,dp,result);
        return result;
    }
};