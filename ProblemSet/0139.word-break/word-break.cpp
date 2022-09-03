class Solution {
public:
    bool dp(string s,int i,unordered_set<string>& wordDict,vector<int>& memo)
    {
        if(i==s.length()) return true;
        if(memo[i]!=-1)
            return memo[i]==1?true:false;
        for(string word:wordDict)
        {
            int len=word.length();
            string temp=s.substr(i,len);
            if(word==temp)
            {
                if(dp(s,i+len,wordDict,memo))
                {
                    memo[i]=1;
                    return true;
                }
            }
        }
        memo[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        vector<int> memo(s.length(),-1);
        for(string word:wordDict) us.insert(word);
        return dp(s,0,us,memo);
    }
};