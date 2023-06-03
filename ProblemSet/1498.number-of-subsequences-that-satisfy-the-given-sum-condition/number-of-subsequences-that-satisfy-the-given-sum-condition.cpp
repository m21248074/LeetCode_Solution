class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int result=0;
        int mod=1e9+7;
        int left=0,right=n-1;
        vector<int> pre(n,1);
        for(int i=1;i<n;i++)
            pre[i]=2*pre[i-1]%mod;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                result=(long(pre[right-left])+long(result))%mod;
                left++;
            }
            else
                right--;
        }
        return result;
    }
};