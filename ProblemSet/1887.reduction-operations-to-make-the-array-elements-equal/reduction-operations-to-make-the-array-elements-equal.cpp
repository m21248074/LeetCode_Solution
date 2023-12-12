class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i]!=nums[i-1])
                result+=n-i;
        }
        return result;
    }
};