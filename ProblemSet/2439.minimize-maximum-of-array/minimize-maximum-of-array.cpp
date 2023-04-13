class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum=nums[0],maxValue=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            maxValue=max(maxValue,(long long)ceil((double)sum/(double)(i+1)));
        }
        return maxValue;
    }
};