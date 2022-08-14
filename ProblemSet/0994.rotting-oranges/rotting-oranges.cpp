class Solution {
public:
    void helper(vector<vector<int>>& grid,int x,int y,int &left,queue<pair<int,int>> &q)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(x<0||x>=m||y<0||y>=n||grid[x][y]!=1) return;
        grid[x][y]=2;
        q.push({x,y});
        left--;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int left=0;
        int result=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    left++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        while(!q.empty()&&left>0)
        {
            for(int i=q.size();i>0;i--)
            {
                pair<int,int> t=q.front();
                q.pop();
                helper(grid,t.first+1,t.second,left,q);
                helper(grid,t.first-1,t.second,left,q);
                helper(grid,t.first,t.second+1,left,q);
                helper(grid,t.first,t.second-1,left,q);
            }
            result++;
        }
        return left>0?-1:result;

    }
};