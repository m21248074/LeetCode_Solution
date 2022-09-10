class Solution {
public:
    int helper(int d,int k,unordered_map<int,unordered_map<int,int>> &dp)
    {
        if(d>k)
            return 0;
        else if(d==k)
            return 1;
        if(!dp.count(d)||!dp[d].count(k))
            dp[d][k]=(helper(d+1,k-1,dp)+helper(d+(d?-1:1),k-1,dp))%1000000007;
        return dp[d][k];
    }
    int numberOfWays(int startPos, int endPos, int k) {
        unordered_map<int,unordered_map<int,int>> dp;
        return helper(abs(startPos-endPos),k,dp);
    }
};