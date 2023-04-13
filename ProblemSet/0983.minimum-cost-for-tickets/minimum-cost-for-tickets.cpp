class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.back();
        vector<int> dp(n+1);
        for(int i=1,j=0;i<=n;i++)
        {
            if(i==days[j])
            {
                j++;
                dp[i]=min(
                    {
                        costs[0]+dp[i-1],
                        costs[1]+dp[i-min(i,7)],
                        costs[2]+dp[i-min(i,30)]
                    }
                );
            }
            else
                dp[i]=dp[i-1];
        }
        return dp[n];
    }
};