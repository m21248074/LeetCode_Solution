class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        int m=grid.size();
        int n=grid[0].size();
        int temp=grid[m-1][n-1];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int t=grid[i][j];
                grid[i][j]=temp;
                temp=t;
            }
        }
        return shiftGrid(grid,k-1);
    }
};