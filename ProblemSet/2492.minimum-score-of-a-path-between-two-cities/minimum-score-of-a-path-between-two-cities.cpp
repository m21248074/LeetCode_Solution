class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> ufs(n+1);
        unordered_map<int,int> um;
        for(int i=1;i<=n;i++)
            ufs[i]=i;
        function<int(int)> find=[&](int x)->int{
            if(ufs[x]!=x)
                ufs[x]=find(ufs[x]);
            return ufs[x];
        };
        for(auto road:roads)
        {
            int parent_x=find(road[0]);
            int parent_y=find(road[1]);
            int value=road[2];
            if(parent_x!=parent_y)
            {
                ufs[parent_x]=parent_y;
                if(um.count(parent_x))
                    value=min(value,um[parent_x]);
            }
            if(um.count(parent_y))
                value=min(value,um[parent_y]);
            um[parent_y]=value;
        }
        return um[find(1)];
    }
};