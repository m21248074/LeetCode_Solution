class Solution {
public:
    int numberOfArrays(string s, int k) {
        int mod=1e9+7;
        int n=s.length();
        vector<int> dp(n+1,0);
        function<int(int)> helper=[&](int index)->int{
            if(index==n)
                return 1;
            if(s[index]=='0')
                return 0;
            if(!dp[index])
            {
                for(long size=1,num=0;index+size<=n;size++)
                {
                    num=num*10+s[index+size-1]-'0';
                    if(num>k)
                        break;
                    dp[index]=(dp[index]+helper(index+size))%mod;
                }
            }
            return dp[index];
        };
        return helper(0);
    }
};