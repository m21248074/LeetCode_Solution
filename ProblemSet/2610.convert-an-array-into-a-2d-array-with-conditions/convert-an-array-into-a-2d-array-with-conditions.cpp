class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> um;
        int maxCnt=0;
        for(int num:nums)
        {
            um[num]++;
            maxCnt=max(maxCnt,um[num]);
        }
        vector<vector<int>> result(maxCnt);
        for(auto i:um)
        {
            int num=i.first;
            int cnt=i.second;
            for(int j=0;j<cnt;j++)
                result[j].push_back(num);
        }
        return result;
    }
};