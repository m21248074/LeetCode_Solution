class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2000));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int difference=nums[i]-nums[j]+1000;
                dp[i][difference]=dp[j][difference]+1;
                result=max(result,dp[i][difference]);
            }
        }
        return result+1;
    }
};