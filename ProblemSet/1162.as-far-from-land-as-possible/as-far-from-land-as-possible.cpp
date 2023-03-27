class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int result=0;
        int n=grid.size();
        vector<int> dirs({0,1,0,-1,0});
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j]) continue;
                q.push(make_pair(i,j));
            }
        }
        if(!q.size()||q.size()==n*n) return -1;
        while(!q.empty())
        {
            result++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int x=temp.first+dirs[i];
                    int y=temp.second+dirs[i+1];
                    if(x<0||x>=n||y<0||y>=n||grid[x][y]) continue;
                    grid[x][y]=result;
                    q.push(make_pair(x,y));
                }
            }
        }
        return result-1;
    }
};