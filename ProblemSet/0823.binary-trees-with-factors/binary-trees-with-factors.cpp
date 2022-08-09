class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const long MOD=1000000007;
        sort(arr.begin(),arr.end());
        unordered_map<int,long> dp;
        for(int i=0;i<arr.size();i++)
        {
            dp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0&&dp[arr[i]/arr[j]])
                    dp[arr[i]]+=(dp[arr[j]]*dp[arr[i]/arr[j]])%MOD;
            }
        }
        long result=0;
        for(auto i:dp)
            result+=i.second;
        return result%MOD;
    }
};