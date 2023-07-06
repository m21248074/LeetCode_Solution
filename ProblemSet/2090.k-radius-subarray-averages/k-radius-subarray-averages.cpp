class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0) return nums;
        long sum=0;
        vector<int> result(n,-1);
        int len=2*k+1;
        if(n<len)
            return result;
        int left=0;
        int right=0;
        while(right<n)
        {
            sum+=nums[right++];
            if(right-left==len)
            {
                result[left+k]=sum/len;
                sum-=nums[left++];
            }
        }
        return result;
    }
};