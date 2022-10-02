class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> result;
        int n=nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        for(int i=1;i<n;i++)
            if(nums[i]<=nums[i-1]) dp1[i]=dp1[i-1]+1;
        for(int i=n-2;i>=0;i--)
            if(nums[i]<=nums[i+1]) dp2[i]=dp2[i+1]+1;
        for(int i=k;i<n-k;i++)
            if(dp1[i-1]>=k&&dp2[i+1]>=k) result.push_back(i);
        return result;
    }
};