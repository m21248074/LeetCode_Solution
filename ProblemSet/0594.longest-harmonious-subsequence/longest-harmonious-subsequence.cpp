class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int num:nums)
            um[num]++;
        int result=0;
        for(int num:nums)
        {
            if(um[num+1]>0)
                result=max(result,um[num]+um[num+1]);
        }
        return result;
    }
};