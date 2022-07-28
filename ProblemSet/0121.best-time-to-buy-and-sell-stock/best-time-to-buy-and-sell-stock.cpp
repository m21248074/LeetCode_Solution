class Solution {
public:
    int double_max(int a,int b)
    {
        return (a>b)?a:b;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0)); //[n][2]
        for(int i=0;i<prices.size();i++)
        {
            if(!i)
            {
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }
            dp[i][0]=double_max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=double_max(dp[i-1][1],-prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};