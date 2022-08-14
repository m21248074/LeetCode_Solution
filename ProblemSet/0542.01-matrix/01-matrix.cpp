class Solution {
public:
    void helper(vector<vector<int>>& mat,int x,int y,int a,int b,queue<pair<int,int>> &q)
    {
        int r=mat.size();
        int c=mat[0].size();
        if(x<0||y<0||x>=r||y>=c||mat[x][y]<=mat[a][b]+1) return;
        mat[x][y]=mat[a][b]+1;
        q.push({x,y});
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j])
                    mat[i][j]=INT_MAX;
                else
                    q.push({i,j});
            }
        }
        while(!q.empty())
        {
            pair<int,int> t=q.front();
            q.pop();
            helper(mat,t.first+1,t.second,t.first,t.second,q);
            helper(mat,t.first-1,t.second,t.first,t.second,q);
            helper(mat,t.first,t.second+1,t.first,t.second,q);
            helper(mat,t.first,t.second-1,t.first,t.second,q);
        }
        return mat;
    }
};