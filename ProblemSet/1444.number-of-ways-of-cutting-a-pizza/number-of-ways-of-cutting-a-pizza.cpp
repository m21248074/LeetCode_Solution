class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        constexpr int mod=1e9+7;
        int m=pizza.size();
        int n=pizza[0].length();
        vector<vector<int>> prefix(m+1,vector<int>(n+1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                prefix[i+1][j+1]=prefix[i+1][j]+prefix[i][j+1]+(pizza[i][j]=='A')-prefix[i][j];
        }
        function<bool(int,int,int,int)> hasAnyApple=[&](int x1,int y1,int x2, int y2)->bool{
            return (prefix[x2+1][y2+1]-prefix[x1][y2+1]-prefix[x2+1][y1]+prefix[x1][y1])>0;
        };
        vector<vector<vector<int>>> temp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        // dp(x, y, k) := ways to cut pizza[x:m][y:n] with k cuts
        function<int(int,int,int)> dp=[&](int x,int y,int k)->int{
            if(k==0) return hasAnyApple(x,y,m-1,n-1);
            int &t=temp[x][y][k];
            if(t!=-1) return t;
            t=0;
            for(int i=x;i<m-1;i++)
                t=(t+hasAnyApple(x,y,i,n-1)*dp(i+1,y,k-1))%mod;
            for(int j=y;j<n-1;j++)
                t=(t+hasAnyApple(x,y,m-1,j)*dp(x,j+1,k-1))%mod;
            return t;
        };
        return dp(0,0,k-1);
    }
};