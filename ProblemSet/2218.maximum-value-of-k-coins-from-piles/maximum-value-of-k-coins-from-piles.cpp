class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        vector<vector<int>> preSum(n);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            preSum[i].push_back(0);
            for(int j=0;j<piles[i].size();j++)
            {
                sum+=piles[i][j];
                preSum[i].push_back(sum);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                for(int t=0;t<=min(j,(int)piles[i].size());t++)
                    dp[i][j]=max(dp[i][j],(i==0?0:dp[i-1][j-t])+preSum[i][t]);
            }
        }
        return dp[n-1][k];
    }
};