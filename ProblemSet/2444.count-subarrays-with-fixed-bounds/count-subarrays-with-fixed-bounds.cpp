class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result=0;
        int n=nums.size();
        int jbad=-1;
        int jmin=-1;
        int jmax=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minK||nums[i]>maxK)
                jbad=i;
            if(nums[i]==minK)
                jmin=i;
            if(nums[i]==maxK)
                jmax=i;
            result+=max(0,min(jmin,jmax)-jbad);
        }
        return result;
    }
};