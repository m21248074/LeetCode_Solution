class Solution {
private:
    vector<int> dp;
public:
    int helper(vector<int>& nums, int target)
    {
        int n=nums.size();
        if(!target) return 1;
        int ans=0;
        if(dp[target]!=-1) return dp[target];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target)
                ans+=helper(nums,target-nums[i]);
        }
        dp[target]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp=vector<int>(target+1,-1);
        return helper(nums,target);
    }
};