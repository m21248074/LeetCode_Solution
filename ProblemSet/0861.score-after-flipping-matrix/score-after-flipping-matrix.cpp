class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=(1<<(n-1))*m;
        for(int j=1;j<n;j++) {
            int cnt=0;
            for(int i=0;i<m;i++)
                cnt+=(grid[i][j]==grid[i][0]);
            result+=max(cnt,m-cnt)*(1<<(n-1-j));
        }
        return result;
    }
};