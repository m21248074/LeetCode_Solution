class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result=0;
        int sum=0;
        int n=nums.size();
        unordered_map<int,int> um;
        um[0]=1;
        for(int num:nums)
        {
            sum=(sum+num%k+k)%k;
            result+=um[sum];
            um[sum]++;
        }

        return result;
    }
};