class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++)
            um[nums[i]].push_back(i);
        int degree=0;
        for(auto i:um)
            degree=max(degree,int(i.second.size()));
        int result=INT_MAX;
        for(auto i:um)
        {
            if(degree==int(i.second.size()))
                result=min(result,i.second[degree-1]-i.second[0]+1);
        }
        return result;
    }
};