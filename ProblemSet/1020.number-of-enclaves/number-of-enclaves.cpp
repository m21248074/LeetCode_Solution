class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        function<void(int,int)> dfs=[&](int i,int j){
            if(i<0||j<0||i>=m||j>=n||!grid[i][j])
                return;
            grid[i][j]=0;
            dfs(i+1,j);
            dfs(i-1,j);
            dfs(i,j+1);
            dfs(i,j-1);
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1)
                    dfs(i,j);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j])
                    result++;
            }
        }
        return result;
    }
};