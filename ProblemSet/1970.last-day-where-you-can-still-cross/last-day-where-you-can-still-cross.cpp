class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        vector<int> parent(n+2);
        vector<int> dirs({-1,0,1,0,-1});
        function<int(int)> find=[&](int x){
            if(x!=parent[x])
                parent[x]=find(parent[x]);
            return parent[x];
        };
        function<void(int,int)> _union=[&](int x,int y){
            parent[find(x)]=find(y);
        };
        function<bool(int,int)> connected=[&](int x,int y){
            return find(x)==find(y);
        };
        function<bool(int,int)> isValid=[&](int x,int y){
            return x>=0&&x<row&&y>=0&&y<col;
        };
        for(int i=0;i<parent.size();i++)
            parent[i]=i;
        for(int i=0;i<col;i++)
        {
            _union(i,n);
            _union(n-i-1,n+1);
        }
        vector<vector<int>> grids(row,vector<int>(col));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                grids[i][j]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            int x0=cells[i][0]-1;
            int y0=cells[i][1]-1;
            grids[x0][y0]=0;
            for(int j=0;j<4;j++)
            {
                int x=x0+dirs[j];
                int y=y0+dirs[j+1];
                if(isValid(x,y)&&grids[x][y]==0)
                    _union(x0*col+y0,x*col+y);
            }
            if(connected(n,n+1))
                return i;
        }
        return -1;
    }
};