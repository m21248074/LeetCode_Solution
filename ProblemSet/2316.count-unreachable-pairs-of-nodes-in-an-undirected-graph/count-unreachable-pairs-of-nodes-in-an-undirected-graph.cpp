class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long result=0;
        if(!edges.size())
            return (long long)n*(long long)(n-1)/2ll;
        vector<int> parent(n);
        function<int(int)> find=[&](int x)->int{
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        };
        function<void(int,int)> _union=[&](int x,int y)->void{
            int parent_x=find(x);
            int parent_y=find(y);
            if(parent_x!=parent_y)
                parent[parent_x]=parent_y;
        };
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(auto edge:edges)
            _union(edge[0],edge[1]);
        unordered_map<int,int> um;
        for(int i=0;i<n;i++)
            um[find(i)]++;
        vector<int> temp;
        for(auto i:um)
            temp.push_back(i.second);
        int len=temp.size();
        for(int i=0;i<len-1;i++)
        {
            for(int j=i+1;j<len;j++)
                result+=(long long)temp[i]*(long long)temp[j];
        }
        return result;
    }
};