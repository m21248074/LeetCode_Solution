class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result=1,length=0;
        int maxNum=*max_element(nums.begin(),nums.end());
        for(int num:nums)
        {
            if(num==maxNum) length++;
            else length=0;
            result=max(length,result);
        }
        return result;
    }
};