class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,0);
        vector<int> parent(n,0);
        vector<int> result;
        int mx=0;
        int mx_index=0;
        for(int i=n;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(nums[j]%nums[i]==0&&dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                    if(mx<dp[i])
                    {
                        mx=dp[i];
                        mx_index=i;
                    }
                }
            }
        }
        for(int i=0;i<mx;i++)
        {
            result.push_back(nums[mx_index]);
            mx_index=parent[mx_index];
        }
        return result;
    }
};