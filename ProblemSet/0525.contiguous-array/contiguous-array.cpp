class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int n=nums.size();
        int result=0;
        int sum=0;
        unordered_map<int,int> um{{0,-1}};
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]==1?1:-1;
            if(um.count(sum))
                result=max(result,i-um[sum]);
            else
                um[sum]=i;
        }
        return result;
    }
};