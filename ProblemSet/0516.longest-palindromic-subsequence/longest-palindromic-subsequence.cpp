class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int)> helper=[&](int left,int right)->int
        {
            if(dp[left][right]!=-1) return dp[left][right];
            if(left==right) return 1;
            else if(left>right) return 0;
            if(s[left]==s[right])
                return dp[left][right]=helper(left+1,right-1)+2;
            return dp[left][right]=max(helper(left+1,right),helper(left,right-1));
        };
        return helper(0,n-1);
    }
};