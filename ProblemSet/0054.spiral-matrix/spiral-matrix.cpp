class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int visited=INT_MAX;
        vector<int> result;
        vector<vector<int>> dirs({{0,1},{1,0},{0,-1},{-1,0}});
        int x=0,y=0;
        int d=0;
        for(int i=0;i<m*n;i++)
        {
            result.push_back(matrix[x][y]);
            matrix[x][y]=visited;
            vector<int> dir=dirs[d];
            if(x+dir[0]<0||x+dir[0]>=m||y+dir[1]<0||y+dir[1]>=n||matrix[x+dir[0]][y+dir[1]]==visited)
            {
                d=(d+1)%4;
                dir=dirs[d];
            }
            x+=dir[0];
            y+=dir[1];
        }
        return result;
    }
};