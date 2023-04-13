class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        function<void(int,int)> dfs=[&](int i,int j){
            if(i<0||i>=m||j<0||j>=n||grid[i][j])
                return;
            grid[i][j]=2;
            dfs(i+1,j);
            dfs(i-1,j);
            dfs(i,j+1);
            dfs(i,j-1);
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0||j==0||i==m-1||j==n-1)&&!grid[i][j])
                    dfs(i,j);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j])
                {
                    dfs(i,j);
                    result++;
                }
            }
        }
        return result;
    }
};