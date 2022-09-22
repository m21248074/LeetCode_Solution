class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m)); //[s][m]
        for(int i=m-1;i>=0;i--) //[s][i]
        {
            for(int s=0;s<=i;s++)
            {
                int e=n-i-1+s;
                if(i==m-1) // base case
                    dp[s][i]=max(multipliers[i]*nums[s],multipliers[i]*nums[e]);
                else
                    dp[s][i]=max(multipliers[i]*nums[s]+dp[s+1][i+1],multipliers[i]*nums[e]+dp[s][i+1]);
            }
        }
        return dp[0][0];
    }
};