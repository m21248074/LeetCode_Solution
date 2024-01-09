class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        function<int(int,int)> getValue=[&](int x,int y)->int{
            int cnt=0;
            int sum=0;
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(x+i<0||y+j<0||x+i==m||y+j==n)
                        continue;
                    cnt++;
                    sum+=img[x+i][y+j];
                }
            }
            return sum/cnt;
        };
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                result[i][j]=getValue(i,j);
        }
        return result;
    }
};