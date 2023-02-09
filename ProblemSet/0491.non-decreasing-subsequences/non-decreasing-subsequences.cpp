class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        int n=nums.size();
        vector<int> temp;
        function<void(int)> helper=[&](int start) -> void {
            if(temp.size()>=2)
                s.insert(temp);
            for(int i=start;i<n;i++)
            {
                if(!temp.empty()&&temp.back()>nums[i])
                    continue;
                temp.push_back(nums[i]);
                helper(i+1);
                temp.pop_back();
            }
        };
        helper(0);
        return vector<vector<int>>(s.begin(),s.end());
    }
};