class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int s=0;
        int e=0;
        long sum=0;
        int result=0;
        while(e<n)
        {
            sum+=nums[e];
            while(sum+k<(long)nums[e]*(e-s+1))
            {
                sum-=nums[s];
                s++;
            }
            result=max(result,e-s+1);
            e++;
        }
        return result;
    }
};