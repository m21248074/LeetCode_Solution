class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> preSum;
        preSum.push_back(0);
        for(int i=0;i<nums.size();i++)
            preSum.push_back(nums[i]+preSum[i]);
        int sum=preSum[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            if(sum-preSum[i+1]==preSum[i])
                return i;
        }
        return -1;
    }
};