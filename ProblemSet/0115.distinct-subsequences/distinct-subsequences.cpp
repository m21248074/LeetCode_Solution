class Solution {
public:
    int dp(string s,int i,string t,int j,vector<vector<int>>& memo)
    {
        if(j==t.length()) return 1;
        else if(t.length()-j>s.length()-i) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int result=0;

        // for(int k=i;k<s.length();k++)
        // {
        //     if(t[j]==s[k])
        //         result+=dp(s,k+1,t,j+1,memo);
        // }

        if(s[i]!=t[j])
            result=dp(s,i+1,t,j,memo);
        else // s[i]==t[j]
            result=dp(s,i+1,t,j+1,memo)+dp(s,i+1,t,j,memo);

        memo[i][j]=result;
        return result;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.length(),vector<int>(t.length(),-1));
        return dp(s,0,t,0,memo);
    }
};