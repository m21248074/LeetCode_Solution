class Solution {
public:
    int helper(int n,vector<int> &dp)
    {
        if(dp[n]!=-1) return dp[n];
        if(n==0) return 0;
        else if(n<3) return 1;
        dp[n]=helper(n-3,dp)+helper(n-2,dp)+helper(n-1,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};