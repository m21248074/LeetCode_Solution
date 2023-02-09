class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> um;
        set<int> s;
        for(auto i:trust)
        {
            int x=i[0];
            int y=i[1];
            // x trust y
            s.insert(x);
            um[y]++;
        }
        for(auto i:um)
        {
            if(i.second==n-1&&!s.count(i.first))
                return i.first;
        }
        return um.empty()&&n==1?1:-1;
    }
};