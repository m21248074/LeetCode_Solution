class Solution {
private:
    bool helper(string word1,string word2)
    {
        int m=word1.size();
        int n=word2.size();
        int i=0;
        for(int j=0;j<n;j++)
            if(word2[j]==word1[i]) i++;
        return i==m;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        int result=1;
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size()<b.size();
        });
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(words[j].size()+1<words[i].size()) break;
                if(words[j].size()==words[i].size()) continue;
                if(helper(words[j],words[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    result=max(result,dp[i]);
                }
            }
        }
        return result;
    }
};