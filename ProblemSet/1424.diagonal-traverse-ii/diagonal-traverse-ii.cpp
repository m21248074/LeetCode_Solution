class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(m.size()<=i+j)
                    m.push_back({});
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> result;
        for(auto i:m)
            result.insert(result.end(),i.rbegin(),i.rend());
        return result;
    }
};