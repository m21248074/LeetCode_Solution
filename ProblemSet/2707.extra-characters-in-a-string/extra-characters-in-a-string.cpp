class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> words(dictionary.begin(),dictionary.end());
        int n=s.length();
        vector<int> dp(n+1,n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1]+1;
            for(int j=1;j<=i;j++)
            {
                if(words.find(s.substr(i-j,j))!=words.end())
                    dp[i]=min(dp[i],dp[i-j]);
            }
        }
        return dp[n];
    }
};