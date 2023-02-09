class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dp(k+2,vector<int>(n,INT_MAX/2));
        dp[0][src]=0;
        for(int i=1;i<=k+1;i++)
        {
            dp[i][src]=0;
            for(auto j:flights)
                dp[i][j[1]]=min(dp[i][j[1]],dp[i-1][j[0]]+j[2]);
        }
        return dp[k+1][dst]>=(INT_MAX/2)?-1:dp[k+1][dst];
    }
};