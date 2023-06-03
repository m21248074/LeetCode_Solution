class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod=1e9+7;
        vector<int> dp(high+1);
        dp[0]=1;
        int result=0;
        for(int i=1;i<=high;i++)
        {
            if(i-zero>=0)
                dp[i]=(dp[i]+dp[i-zero])%mod;
            if(i-one>=0)
                dp[i]=(dp[i]+dp[i-one])%mod;
            if(i>=low&&i<=high)
                result=(result+dp[i])%mod;
        }
        return result;
    }
};