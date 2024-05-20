class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        for(int num:nums)
        {
            int idx=abs(num)-1;
            if(nums[idx]<0)
                result.push_back(idx+1);
            else
                nums[idx]=-nums[idx];
        }
        return result;
    }
};