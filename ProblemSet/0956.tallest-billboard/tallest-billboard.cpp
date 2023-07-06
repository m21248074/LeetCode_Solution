class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<int> dp(5001,INT_MIN);
        dp[0]=0;
        for(int rod:rods)
        {
            vector<int> cur=dp;
            for(int i=0;i+rod<=5000;i++)
            {
                dp[i+rod]=max(dp[i+rod],cur[i]);
                dp[abs(i-rod)]=max(dp[abs(i-rod)],cur[i]+min(i,rod));
            }
        }
        return dp[0];
    }
};