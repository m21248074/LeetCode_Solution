class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int curMin=0;
        int mn=INT_MAX;
        int curMax=0;
        int mx=INT_MIN;
        for(int num:nums)
        {
            sum+=num;
            curMin=min(num,curMin+num);
            curMax=max(num,curMax+num);
            mn=min(curMin,mn);
            mx=max(curMax,mx);
        }
        if(sum==mn)
            return mx;
        return max(mx,sum-mn);
    }
};