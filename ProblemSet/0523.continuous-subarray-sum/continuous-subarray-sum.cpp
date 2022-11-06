class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> um;
        um[0]=-1;
        int prefix=0;
        for(int i=0;i<n;i++)
        {
            prefix=(prefix+nums[i])%k;
            um.insert({prefix,i});
            if(i-um[prefix]>=2)
                return true;
        }
        return false;
    }
};