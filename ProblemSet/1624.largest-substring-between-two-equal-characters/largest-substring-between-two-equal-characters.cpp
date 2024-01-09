class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,pair<int,int>> um;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(!um.count(c))
                um[c].first=i;
            um[c].second=i;
        }
        int result=-1;
        for(auto i:um)
        {
            if(i.second.first==i.second.second)
                continue;
            result=max(result,i.second.second-i.second.first-1);
        }
        return result;
    }
};