class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++)
            prefix[i+1]=prefix[i]+nums[i];
        long long result=-1;
        for(int i=2;i<n;i++)
        {
            if(nums[i]<prefix[i])
                result=nums[i]+prefix[i];
        }
        return result;
    }
};