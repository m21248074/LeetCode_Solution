class Solution {
public:
    int helper(vector<int>& nums,int start,vector<int>& dp)
    {
        if(start>=nums.size()) return 0;
        if(dp[start]!=-1) return dp[start];
        int result=max(helper(nums,start+1,dp),helper(nums,start+2,dp)+nums[start]);
        dp[start]=result;
        return result;
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,0,dp);
    }
};