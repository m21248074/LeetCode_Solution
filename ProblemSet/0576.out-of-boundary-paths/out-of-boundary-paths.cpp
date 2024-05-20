class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1,vector<vector<int>>(m,vector<int>(n,0)));
        for(int k=1;k<=maxMove;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    long long left=(i==0)?1:dp[k-1][i-1][j];
                    long long right=(i==m-1)?1:dp[k-1][i+1][j];
                    long long up=(j==0)?1:dp[k-1][i][j-1];
                    long long down=(j==n-1)?1:dp[k-1][i][j+1];
                    dp[k][i][j]=(left+right+up+down)%(int)(1e9+7);
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};