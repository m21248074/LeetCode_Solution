class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n);
        function<int(int)> find=[&](int x)->int
        {
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        };
        function<bool(int,int)> _union=[&](int x,int y)->bool
        {
            int parent_x=find(x);
            int parent_y=find(y);
            if(parent_x!=parent_y)
            {
                parent[parent_x]=parent_y;
                return true;
            }
            return false;
        };
        for(int i=0;i<n;i++)
            parent[i]=i;
        int extraLine=0;
        for(auto connection:connections)
        {
            if(!_union(connection[0],connection[1]))
                extraLine++;
        }
        unordered_set<int> us;
        for(int i=0;i<n;i++)
            us.insert(find(i));
        if(us.size()-1>extraLine)
            return -1;
        return us.size()-1;
    }
};