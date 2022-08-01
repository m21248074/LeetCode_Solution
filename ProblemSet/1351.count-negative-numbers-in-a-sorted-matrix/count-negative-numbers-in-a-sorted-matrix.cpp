class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int result=0;
        int i=0,j=c-1;
        while(i<r&&j>=0)
        {
            if(grid[i][j]<0)
            {
                result+=r-i;
                j--;
            }
            else
                i++;
        }
        return result;
    }
};