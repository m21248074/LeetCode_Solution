class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        function<int(int,int)> helper=[&](int x,int y)->int{
            if(x<0||x>=m||y<0||y>=n||grid[x][y]==0) return 0;
            int val=grid[x][y],mx=0;
            grid[x][y]=0;
            mx=max({helper(x+1,y),helper(x-1,y),helper(x,y+1),helper(x,y-1)});
            grid[x][y]=val;
            return mx+val;
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j])
                    continue;
                result=max(result,helper(i,j));
            }
        }
        return result;
    }
};