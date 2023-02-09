class Solution {
public:
    void helper(vector<vector<int>>& grid,int &remaining,int i,int j,int &result)
    {
        int m=grid.size(),n=grid[0].size();
        vector<int> dirs({0,1,0,-1,0});
        if(i<0||j<0||i>=m||j>=n||grid[i][j]<0) return;
        if(grid[i][j]==2)
        {
            if(!remaining) result++;
            return;
        }
        grid[i][j]=-2;
        remaining--;
        for(int k=0;k<4;k++)
            helper(grid,remaining,i+dirs[k],j+dirs[k+1],result);
        grid[i][j]=0;
        remaining++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int startX=0,startY=0;
        int result=0;
        int remaining=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    startX=i,startY=j;
                else if(grid[i][j]==0)
                    remaining++;
            }
        }
        helper(grid,remaining,startX,startY,result);
        return result;
    }
};