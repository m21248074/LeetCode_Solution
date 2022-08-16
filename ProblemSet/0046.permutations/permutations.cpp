class Solution {
public:
    void helper(vector<vector<int>>& results,vector<int>& nums,int start)
    {
        if(start>=nums.size())
        {
            vector<int> result(nums);
            results.push_back(result);
            return;
        }
        for(int i=start;i<nums.size();i++)
        {
            swap(nums[start],nums[i]);
            helper(results,nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        helper(results,nums,0);
        return results;
    }
};