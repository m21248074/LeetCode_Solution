class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        for(int i=0;i<prices.size();i++)
        {
            if(!i)
            {
                dp[i][0]=0;
                dp[i][1]=-prices[i]-fee;
                continue;
            }
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[prices.size()-1][0];
    }
};