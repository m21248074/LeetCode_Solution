class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int result=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0]=grid[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                        dp[i][j]=min(dp[i][j],grid[i][j]+dp[i-1][k]);
                }
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};