class Solution {
public:
    void helper(vector<int>& candidates,vector<vector<int>> &result,vector<int> &cur,int start,int target)
    {
        if(target<0) return;
        else if(target==0)
        {
            result.push_back(cur);
            return;
        }
        for(int i=start;i<candidates.size();i++)
        {
            int candidate=candidates[i];
            cur.push_back(candidate);
            helper(candidates,result,cur,i,target-candidate);
            cur.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        helper(candidates,result,cur,0,target);
        return result;
    }
};