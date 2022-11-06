class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(k>=m+n-2) return m+n-2;
        vector<vector<int>> visited(m,vector<int>(n,-1));
        queue<vector<int>> q;
        q.push(vector<int>({0,0,0,k}));
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            int x=t[0],y=t[1],step=t[2],newK=t[3];
            if(x<0||y<0||x>=m||y>=n) continue;
            if(x==m-1&&y==n-1) return step;
            if(grid[x][y])
            {
                if(newK>0)
                    newK--;
                else // newK<=0
                    continue;
            }
            if(visited[x][y]!=-1&&visited[x][y]>=newK)
                continue;
            visited[x][y]=newK;
            q.push(vector<int>({x+1,y,step+1,newK}));
            q.push(vector<int>({x,y+1,step+1,newK}));
            q.push(vector<int>({x-1,y,step+1,newK}));
            q.push(vector<int>({x,y-1,step+1,newK}));
        }
        return -1;
    }
};