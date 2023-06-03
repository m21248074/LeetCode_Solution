class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=INT_MIN;
            for(int j=0,take=0;j<3&&i+j<n;j++)
            {
                take+=stoneValue[i+j];
                dp[i]=max(dp[i],take-dp[i+j+1]);
            }
        }
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        return "Tie";
    }
};