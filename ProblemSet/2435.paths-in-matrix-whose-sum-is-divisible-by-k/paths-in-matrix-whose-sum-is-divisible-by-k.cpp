class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int a=1e9+7;
        vector<vector<int>> dp(50001,vector<int>(51,-1));
        function<int(int,int,int)> helper=[&](int i,int j,int mod)
        {
            if(i==m||j==n)
                return 0;
            if(i==m-1&&j==n-1)
                return ((mod+grid[i][j])%k)?0:1;
            int index=i*n+j;
            if(dp[index][mod]!=-1) return dp[index][mod];
            dp[index][mod]=(helper(i+1,j,(mod+grid[i][j])%k)+helper(i,j+1,(mod+grid[i][j])%k))%a;
            return dp[index][mod];
        };
        return helper(0,0,0);
    }
};