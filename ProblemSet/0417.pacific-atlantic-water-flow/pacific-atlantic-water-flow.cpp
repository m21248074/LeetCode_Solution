class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int i,int j)
    {
        int m=heights.size();
        int n=heights[0].size();
        visited[i][j]=true;
        vector<vector<int>> dirs({{0,1},{1,0},{0,-1},{-1,0}});
        for(auto dir:dirs)
        {
            int x=i+dir[0];
            int y=j+dir[1];
            if(x>=0&&x<m&&y>=0&&y<n&&!visited[x][y]&&heights[x][y]>=heights[i][j])
                dfs(heights,visited,x,y);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> p_visited(m,vector<bool>(n,false));
        vector<vector<bool>> a_visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            dfs(heights,p_visited,i,0);
            dfs(heights,a_visited,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            dfs(heights,p_visited,0,i);
            dfs(heights,a_visited,m-1,i);
        }
        vector<vector<int>> result;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(p_visited[i][j]&&a_visited[i][j])
                    result.push_back({i,j});
            }
        }
        return result;
    }
};