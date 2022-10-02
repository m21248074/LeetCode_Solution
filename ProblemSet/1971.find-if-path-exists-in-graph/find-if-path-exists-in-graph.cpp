class DisjointSet
{
    private:
        vector<int> parent;
    public:
        DisjointSet(int n)
        {
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find(int x)
        {
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }
        void join(int x,int y)
        {
            int parentX=find(x);
            int parentY=find(y);
            if(parentX==parentY) return;
            parent[parentX]=parentY;
        }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(auto edge:edges)
        {
            int a=edge[0];
            int b=edge[1];
            ds.join(a,b);
        }
        return ds.find(source)==ds.find(destination);
    }
};