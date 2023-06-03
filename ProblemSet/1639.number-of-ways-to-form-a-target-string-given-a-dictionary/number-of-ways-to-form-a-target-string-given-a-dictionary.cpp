class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n=target.length();
        int m=words[0].length();
        int mod=1e9+7;
        vector<long> result(n+1);
        result[0]=1;
        for(int i=0;i<m;i++)
        {
            vector<int> count(26);
            for(string &word:words)
                count[word[i]-'a']++;
            for(int j=n-1;j>=0;j--)
                result[j+1]+=result[j]*count[target[j]-'a']%mod;
        }
        return result[n]%mod;
    }
};