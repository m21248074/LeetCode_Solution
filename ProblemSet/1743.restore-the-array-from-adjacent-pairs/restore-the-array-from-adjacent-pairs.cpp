class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n=adjacentPairs.size();
        vector<int> result(n+1);
        unordered_map<int,unordered_set<int>> um;
        for(auto pair:adjacentPairs)
        {
            int x=pair[0];
            int y=pair[1];
            um[x].insert(y);
            um[y].insert(x);
        }
        unordered_set<int> r;
        int cur=INT_MAX;
        int i=0;
        for(auto s:um)
        {
            if(s.second.size()==1)
            {
                cur=s.first;
                break;
            }
        }
        result[i]=cur;
        i++;
        r.insert(cur);
        while(i<n+1)
        {
            auto t=um[cur];
            um.erase(cur);
            for(int next:t)
            {
                if(next!=cur&&!r.count(next))
                {
                    r.insert(next);
                    result[i]=next;
                    i++;
                    cur=next;
                }
            }
        }
        return result;
    }
};