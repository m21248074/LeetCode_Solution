class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int n=nums.size();
        int current=0;
        for(int i=0;i<n;i++)
        {
            current=((current<<1)+nums[i])%5;
            result.push_back(current==0);
        }
        return result;
    }
};