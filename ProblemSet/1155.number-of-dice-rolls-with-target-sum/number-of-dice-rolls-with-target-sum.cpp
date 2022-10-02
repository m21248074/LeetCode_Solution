class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;
        //dp[i][j]=dp[i][j]+dp[i-1][k-j]
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                for(int l=j;l<=target;l++)
                    dp[i][l]=(dp[i][l]+dp[i-1][l-j])%int(1e9+7);
            }
        }
        return dp[n][target];
    }
};