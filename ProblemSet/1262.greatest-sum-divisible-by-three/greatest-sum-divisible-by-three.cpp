class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3));
        dp[0] = {0, INT_MIN, INT_MIN};
        for(int i=1;i<=n;i++) {
            int idx = i - 1;
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][nums[idx] % 3] + nums[idx]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][(nums[idx] + 1) % 3] + nums[idx]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][(nums[idx] + 2) % 3] + nums[idx]);
        }
        return dp[n][0];
    }
};