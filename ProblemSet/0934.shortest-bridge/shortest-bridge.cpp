class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int result=0;
        int n=grid.size();
        queue<int> q;
        vector<int> dirs({0,1,0,-1,0});
        int startX,startY;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j]) continue;
                startX=i;
                startY=j;
                break;
            }
        }
        function<void(int,int)> helper=[&](int x,int y){
            if(x<0||x>=n||y<0||y>=n||grid[x][y]==0||grid[x][y]==2)
                return;
            grid[x][y]=2;
            q.push(x*n+y);
            for(int i=0;i<4;i++)
                helper(x+dirs[i],y+dirs[i+1]);
        };
        helper(startX,startY);
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                int t=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int x=t/n+dirs[j],y=t%n+dirs[j+1];
                    if(x<0||x>=n||y<0||y>=n||grid[x][y]==2) continue;
                    if(grid[x][y]==1) return result;
                    grid[x][y]=2;
                    q.push(x*n+y);
                }
            }
            result++;
        }
        return result;
    }
};