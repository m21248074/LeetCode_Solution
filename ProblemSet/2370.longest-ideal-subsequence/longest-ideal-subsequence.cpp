class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.length();
        int result=0;
        vector<int> dp(150);
        for(char i:s)
        {
            for(int j=i-k;j<=i+k;j++)
                dp[i]=max(dp[i],dp[j]);
            dp[i]++;
            result=max(result,dp[i]);
        }
        return result;
    }
};