class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int result=INT_MIN;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r-2;i++)
        {
            for(int j=0;j<c-2;j++)
            {
                int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                result=max(sum,result);
            }
        }
        return result;
    }
};