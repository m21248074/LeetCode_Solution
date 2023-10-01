class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        function<bool(int)> dfs=[&](int index)->bool{
            if(index==n) return true;
            if(dp[index]==-1)
            {
                bool isValid=false;
                if(index+1<n&&nums[index+1]==nums[index])
                    isValid|=dfs(index+2);
                if(index+2<n)
                {
                    if(
                        (nums[index+1]==nums[index]&&nums[index+2]==nums[index])||(nums[index+1]-1==nums[index]&&nums[index+2]-1==nums[index+1])
                    )
                    {
                        isValid|=dfs(index+3);
                    }
                }
                dp[index]=isValid;
            }
            return bool(dp[index]);
        };
        return dfs(0);
    }
};