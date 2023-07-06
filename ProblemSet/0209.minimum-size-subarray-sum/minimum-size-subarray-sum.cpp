class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int result=INT_MAX;
        int left=0;
        int right=0;
        int sum=0;
        while(right<n)
        {
            sum+=nums[right++];
            while(sum>=target)
            {
                result=min(result,right-left);
                sum-=nums[left++];
            }
        }
        return result==INT_MAX?0:result;
    }
};