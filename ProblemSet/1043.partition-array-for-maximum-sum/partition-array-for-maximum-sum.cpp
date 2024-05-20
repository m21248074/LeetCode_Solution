class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++)
        {
            int cur=0;
            for(int j=1;j<=k&&i-j>=0;j++)
            {
                cur=max(cur,arr[i-j]);
                dp[i]=max(dp[i],dp[i-j]+cur*j);
            }
        }
        return dp.back();
    }
};