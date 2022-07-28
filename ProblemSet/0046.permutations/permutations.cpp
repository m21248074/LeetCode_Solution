class Solution {
public:
    void backtrack(vector<int>& track,vector<int>& nums,vector<vector<int>>& result)
    {
        if(track.size()==nums.size())
        {
            result.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(track.begin(),track.end(),nums[i])!=track.end())
                continue;
            track.push_back(nums[i]);
            backtrack(track,nums,result);
            track.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> track;
        backtrack(track,nums,result);
        return result;
    }
};