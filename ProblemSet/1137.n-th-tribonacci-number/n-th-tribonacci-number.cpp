class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        function<int(int)> helper=[&](int n)
        {
            if(dp[n]!=-1) return dp[n];
            if(n==0) return 0;
            else if(n<3) return 1;
            dp[n]=helper(n-3)+helper(n-2)+helper(n-1);
            return dp[n];
        };
        return helper(n);
    }
};