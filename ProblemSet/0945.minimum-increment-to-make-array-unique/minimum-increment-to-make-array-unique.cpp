class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int result=0;
        int need=0;
        sort(nums.begin(),nums.end());
        for (int num:nums)
        {
        	result+=max(need-num,0);
        	need=max(num,need)+1;
        }
        return result;
    }
};