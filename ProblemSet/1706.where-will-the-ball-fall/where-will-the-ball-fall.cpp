class Solution {
public:
    int helper(int i,vector<vector<int>> &grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int r=0;
        int c=i;
        while(r<m)
        {
            int nextC=c+grid[r][c];
            if(nextC<0||nextC>n-1||grid[r][c]!=grid[r][nextC])
                return -1;
            r++;
            c=nextC;
        }
        return c;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++)
            result[i]=helper(i,grid);
        return result;
    }
};