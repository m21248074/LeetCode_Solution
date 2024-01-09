class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> mCnt(m);
        vector<int> nCnt(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    mCnt[i]++;
                    nCnt[j]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                grid[i][j]=2*(mCnt[i]+nCnt[j])-(m+n);
        }
        return grid;
    }
};