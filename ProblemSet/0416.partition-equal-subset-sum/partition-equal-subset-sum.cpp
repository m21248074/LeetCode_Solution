class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(sum%2) return false;
        vector<bool> dp(target+1,false); // size: 0~target
        dp[0]=true;
        for(int num:nums)
            for(int i=target;i>=num;i--) dp[i]=dp[i]||dp[i-num];
        return dp[target];
    }
};