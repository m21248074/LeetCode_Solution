class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int result=0;
        int preSum=0;
        unordered_map<int,int> um{{0,1}};
        for(int num:nums)
        {
            preSum+=num;
            result+=um[preSum-goal];
            um[preSum]++;
        }
        return result;
    }
};