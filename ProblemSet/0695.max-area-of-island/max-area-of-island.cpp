class Solution {
public:
    int deleteIsland(vector<vector<int>>& grid,int x,int y,int &size)
    {
        if(x<grid.size()&&y<grid[0].size()&&grid[x][y]==1)
        {
            size++;
            grid[x][y]=0;
            deleteIsland(grid,x+1,y,size);
            deleteIsland(grid,x-1,y,size);
            deleteIsland(grid,x,y+1,size);
            deleteIsland(grid,x,y-1,size);
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0; //default
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=0;
                    result=max(result,deleteIsland(grid,i,j,temp));
                }
            }
        }
        return result;
    }
};