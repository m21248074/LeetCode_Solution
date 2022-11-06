class Solution {
public:
    int helper(int x)
    {
        if(x>=100) return 4;
        if(x>=10) return 3;
        if(x>=2) return 2;
        return 1;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX-1000));
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=min(i,k);j++)
            {
                if(j>0)
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                int x,y;
                x=y=0;
                for(int l=i;l>=1;l--)
                {
                    if(s[l-1]==s[i-1]) x++;
                    else y++;
                    if(j>=y)
                        dp[i][j]=min(dp[i][j],dp[l-1][j-y]+helper(x));
                }
            }
        }
        return dp[n][k];
    }
};