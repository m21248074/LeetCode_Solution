class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(int num:nums)
            ones+=num;
        if(ones==0||ones==n)
            return 0;
        int nowSum=0;
        for(int i=0;i<ones;i++)
            nowSum+=nums[i];
        int result=ones-nowSum;
        for(int i=1;i<n;i++)
        {
            nowSum-=nums[i-1];
            nowSum+=nums[(i+ones-1)%n];
            result=min(result,ones-nowSum);
        }
        return result;
    }
};