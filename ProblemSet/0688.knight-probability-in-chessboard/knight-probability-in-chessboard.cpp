class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> memo(n+1,vector<vector<double>>(n+1,vector<double>(k+1,0.0)));
        vector<int> dx({-2,-1,1,2,2,1,-1,-2});
        vector<int> dy({1,2,2,1,-1,-2,-2,-1});
        function<double(int,int,int)> dfs=[&](int r,int c,int K)->double{
            if(r>=n||r<0||c>=n||c<0) return 0.0;
            if(memo[r][c][K]!=0.0) return memo[r][c][K];
            if(K==0) return 1.0;
            double result=0.0;
            for(int i=0;i<8;i++)
            {
                int x=r+dx[i];
                int y=c+dy[i];
                result+=0.125*dfs(x,y,K-1);
            }
            memo[r][c][K]=result;
            return result;
        };
        return dfs(row,column,k);
    }
};