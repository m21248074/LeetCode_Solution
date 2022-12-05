class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> um;
        vector<int> zero,one;
        for(auto match:matches)
        {
            if(!um.count(match[0]))
                um[match[0]]=0;
            um[match[1]]++;
        }
        for(auto i:um)
        {
            if(i.second==0) zero.push_back(i.first);
            else if(i.second==1) one.push_back(i.first);
        }
        return vector<vector<int>>({zero,one});
    }
};