class Solution {
public:
    int numTilings(int n) {
        int M=1e9+7;
        vector<long> dp(n+2);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
            dp[i]=(dp[i-1]*2+dp[i-3])%M;
        return dp[n];
    }
};