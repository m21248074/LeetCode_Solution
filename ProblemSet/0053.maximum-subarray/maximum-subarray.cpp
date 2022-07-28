class Solution {
public:
    int doubleMax(int a,int b)
    {
        return (a>b)?a:b;
    }
    int tripleMax(int a,int b,int c)
    {
        return max(max(a,b),c);
    }
    int maxSubArrayCrossing(vector<int>& nums,int l,int m,int r)
    {
        int sum=0;
        int left=INT_MIN;
        for(int i=m;i>=l;i--)
        {
            sum+=nums[i];
            if(sum>left)
                left=sum;
        }
        sum=0;
        int right=INT_MIN;
        for(int i=m+1;i<=r;i++)
        {
            sum+=nums[i];
            if(sum>right)
                right=sum;
        }
        return tripleMax(left,right,left+right);
    }
    int maxSubArrayRange(vector<int>& nums,int l,int r)
    {
        if(l==r)
            return nums[l];
        int m=(l+r)/2;
        return tripleMax(maxSubArrayRange(nums,l,m),maxSubArrayRange(nums,m+1,r),maxSubArrayCrossing(nums,l,m,r));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayRange(nums,0,nums.size()-1);
    }
};