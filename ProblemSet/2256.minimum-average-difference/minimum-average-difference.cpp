class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long suffix=accumulate(nums.begin(),nums.end(),0LL);
        long long prefix=0;
        int best=INT_MAX;
        int result=0;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            suffix-=nums[i];
            int cur=abs(prefix/(i+1)-(i==n-1?0:suffix/(n-i-1)));
            if(cur<best)
            {
                best=cur;
                result=i;
            }
        }
        return result;
    }
};