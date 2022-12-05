class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        int x=entrance[0];
        int y=entrance[1];
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> dirs({-1,0,1,0,-1});
        queue<vector<int>> q;
        q.push({x,y,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int i=p[0];
            int j=p[1];
            int step=p[2];
            if(maze[i][j]=='.'&&(i==0||i==m-1||j==0||j==n-1)&&(i!=x||j!=y)) return step;
            for(int k=0;k<4;k++)
            {
                int new_i=i+dirs[k];
                int new_j=j+dirs[k+1];
                if(new_i<0||new_i>=m||new_j<0||new_j>=n) continue;
                if(visited[new_i][new_j]) continue;
                if(maze[new_i][new_j]=='+') continue;
                q.push({new_i,new_j,step+1});
                visited[new_i][new_j]=1;
            }
        }
        return -1;
    }
};