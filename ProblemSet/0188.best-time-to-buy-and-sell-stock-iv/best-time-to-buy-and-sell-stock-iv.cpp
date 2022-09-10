class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<=0)
            return 0;
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,0)));
        // [n][k][1 or 0]
        for(int i=0;i<prices.size();i++)
        {
            for(int j=k;j>=1;j--)
            {
                if(!i)
                {
                    dp[i][j][0]=0;
                    dp[i][j][1]=-prices[i];
                    continue;
                }
                dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[prices.size()-1][k][0];
    }
};