class UnionFind{
    private:
        vector<int> parent;
    public:
        UnionFind(int n)
        {
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int x)
        {
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }
        void Union(int x,int y)
        {
            int parentX=find(x);
            int parentY=find(y);
            parent[parentX]=parentY;
        }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> x,y;
        int len=edges.size();
        for(int i=0;i<len;i++)
            edges[i].push_back(i);
        sort(edges.begin(),edges.end(),[&](vector<int> &a,vector<int> &b)->bool{
            return a[2]<b[2];
        });
        function<int(int,int)> findMST=[&](int block,int e)->int{
            UnionFind uf(n);
            int weight=0;
            if(e!=-1)
            {
                weight+=edges[e][2];
                uf.Union(edges[e][0],edges[e][1]);
            }
            for(int i=0;i<len;i++)
            {
                if(i==block) continue;
                if(uf.find(edges[i][0])==uf.find(edges[i][1])) continue;
                uf.Union(edges[i][0],edges[i][1]);
                weight+=edges[i][2];
            }
            for(int i=0;i<n;i++)
            {
                if(uf.find(i)!=uf.find(0))
                    return INT_MAX;
            }
            return weight;
        };
        int mst=findMST(-1,-1);
        for(int i=0;i<len;i++)
        {
            if(mst<findMST(i,-1))
                x.push_back(edges[i][3]);
            else if(mst==findMST(-1,i))
                y.push_back(edges[i][3]);
        }
        return {x,y};
    }
};