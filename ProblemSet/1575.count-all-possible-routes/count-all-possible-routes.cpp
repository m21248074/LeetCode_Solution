class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(210,vector<int>(110,0));
        int n=locations.size();
        int mod=1e9+7;
        for(int i=0;i<=fuel;i++)
            dp[i][finish]=1;
        for(int f=1;f<=fuel;f++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int diff=locations[i]-locations[j];
                    if(j!=i&&f>=abs(diff))
                        dp[f][i]=(dp[f][i]+dp[f-abs(diff)][j])%mod;
                }
            }
        }
        return dp[fuel][start];
    }
};