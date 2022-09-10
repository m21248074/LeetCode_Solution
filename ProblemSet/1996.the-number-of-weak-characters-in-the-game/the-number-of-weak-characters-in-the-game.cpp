class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int result=0;
        int maxDef=INT_MIN;
        map<int,vector<int>,greater<int>> m;
        for(auto p:properties) m[p[0]].push_back(p[1]);
        for(auto c:m)
        {
            result+=count_if(c.second.begin(),c.second.end(),[&](int curDef){ return curDef < maxDef; });
            maxDef=max(maxDef,*max_element(c.second.begin(),c.second.end()));
        }
        return result;
    }
};