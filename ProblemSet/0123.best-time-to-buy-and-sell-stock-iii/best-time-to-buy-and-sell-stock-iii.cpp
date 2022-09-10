class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(3,vector<int>(2,0)));
        // [n][k][1 or 0]
        for(int i=0;i<prices.size();i++)
        {
            for(int k=2;k>=1;k--)
            {
                if(!i)
                {
                    dp[i][k][0]=0;
                    dp[i][k][1]=-prices[i];
                    continue;
                }
                dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
                dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[prices.size()-1][2][0];
    }
};