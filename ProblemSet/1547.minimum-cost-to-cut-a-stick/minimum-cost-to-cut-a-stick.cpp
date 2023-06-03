class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(102,vector<int>(102));
        function<int(int,int)> dfs=[&](int i,int j)->int{
            if(j-i<=1) return 0;
            if(!dp[i][j])
            {
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<j;k++)
                    dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+dfs(i,k)+dfs(k,j));
            }
            return dp[i][j];
        };
        return dfs(0,cuts.size()-1);
    }
};