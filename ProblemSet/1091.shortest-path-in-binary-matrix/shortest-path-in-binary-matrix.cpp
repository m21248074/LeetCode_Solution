class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]||grid[n-1][n-1]) return -1;
        if(n==1) return 1;
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=2;
        vector<pair<int,int>> dirs({{0,1},{1,0},{0,-1},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}});
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            int x=t[0],y=t[1],len=t[2];
            for(int i=0;i<8;i++)
            {
                int newX=x+dirs[i].first;
                int newY=y+dirs[i].second;
                if(newX==n-1&&newY==n-1) return len+1;
                else if(newX>=0&&newY>=0&&newX<n&&newY<n&&grid[newX][newY]==0)
                {
                    grid[newX][newY]=2;
                    q.push({newX,newY,len+1});
                }
            }
        }
        return -1;
    }
};
