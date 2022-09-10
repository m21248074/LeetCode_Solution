class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left=0,right=0;
        int result=0;
        int temp=0;
        while(right<nums.size())
        {
            int num=nums[right];
            if((temp&num)==0)
            {
                temp|=num;
                result=max(result,right-left+1);
                right++;
            }
            else
            {
                int num=nums[left];
                temp^=num;
                left++;
            }
        }
        return result;
    }
};