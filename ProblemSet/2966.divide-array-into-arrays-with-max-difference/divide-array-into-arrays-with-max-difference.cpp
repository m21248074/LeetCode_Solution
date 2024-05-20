class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result(n/3,vector<int>(3));
        int j=0;
        for(int i=0;i<n;i+=3)
        {
            if(nums[i+2]-nums[i]<=k)
            {
                result[j]={nums[i],nums[i+1],nums[i+2]};
                j++;
            }
            else
                return {};
        }
        return result;
    }
};