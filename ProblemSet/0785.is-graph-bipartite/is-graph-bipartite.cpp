class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        function<int(int)> find=[&](int x)->int{
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        };
        for(int i=0;i<n;i++)
        {
            if(graph[i].empty()) continue;
            int x=find(i);
            int y=find(graph[i][0]);
            if(x==y) return false;
            for(int j=1;j<graph[i].size();j++)
            {
                int temp=find(graph[i][j]);
                if(x==temp) return false;
                parent[temp]=y;
            }
        }
        return true;
    }
};