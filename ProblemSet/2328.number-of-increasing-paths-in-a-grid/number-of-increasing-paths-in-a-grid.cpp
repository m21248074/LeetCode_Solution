class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int mod=1e9+7;
        long result=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> dirs({-1,0,1,0,-1});
        function<int(int,int)> dfs=[&](int x,int y)->int{
            if(dp[x][y]!=0) return dp[x][y];
            dp[x][y]=1;
            long num=1;
            for(int i=0;i<4;i++)
            {
                int nextX=x+dirs[i],nextY=y+dirs[i+1];
                if(nextX>=0&&nextX<m&&nextY>=0&&nextY<n&&grid[nextX][nextY]>grid[x][y])
                    num=(num+dfs(nextX,nextY))%mod;
            }
            dp[x][y]=num;
            return dp[x][y];
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                result=(result+dfs(i,j))%mod;
        }
        return result%mod;
    }
};