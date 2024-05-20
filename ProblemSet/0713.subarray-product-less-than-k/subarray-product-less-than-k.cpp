class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0)    return 0;
        int result=0;
        int product=1;
        int left=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            product*=nums[i];
            while(left<=i&&product>=k)
                product/=nums[left++];
            result+=i-left+1;

        }
        return result;   
    }
};