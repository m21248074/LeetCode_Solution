class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        long long left=*min_element(nums.begin(),nums.end());
        long long right=*max_element(nums.begin(),nums.end());
        function<long long(long long)> calculateSum=[&](long long mid)-> long long{
            long long result=0;
            for(int i=0;i<n;i++)
                result+=abs(nums[i]-mid)*cost[i];
            return result;
        };
        while(left<right)
        {
            long long mid=(left+right)/2;
            long long leftSum=calculateSum(mid);
            long long rightSum=calculateSum(mid+1);
            if(leftSum<rightSum)
                right=mid;
            else
                left=mid+1;
        }
        return calculateSum(left);
    }
};