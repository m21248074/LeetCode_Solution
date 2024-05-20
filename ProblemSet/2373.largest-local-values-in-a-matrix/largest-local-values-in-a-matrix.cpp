class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> result(m-2,vector<int>(n-2,0));
        for(int i=0;i<m-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int t=0;
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                        t=max(t,grid[k][l]);
                }
                result[i][j]=t;
            }
        }
        return result;
    }
};