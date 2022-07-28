class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> value;
        for(int i=0;i<accounts.size();i++)
        {
            vector<int> temp=accounts[i];
            value.push_back(accumulate(temp.begin(),temp.end(),0));
        }
        sort(value.begin(),value.end(),greater<int>());
        return value[0];
    }
};