class UnionFind {
    private:
        vector<int> parent;
        int n;
    public:
        UnionFind(int n):n(n)
        {
            parent=vector<int>(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int _union(int x,int y)
        {
            int px=find(x);
            int py=find(y);
            if(px==py)
                return 1;
            parent[px]=py;
            n-=1;
            return 0;
        }
        int find(int x)
        {
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }
        int getN()
        {
            return n;
        }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n);
        UnionFind bob(n);
        int result=0;
        for(auto edge:edges)
        {
            if(edge[0]!=3)
                continue;
            result+=alice._union(edge[1]-1,edge[2]-1);
            bob._union(edge[1]-1,edge[2]-1);
        }
        for(auto edge:edges)
        {
            if(edge[0]==3)
                continue;
            UnionFind &cur=(edge[0]==1)?alice:bob;
            result+=cur._union(edge[1]-1,edge[2]-1);
        }
        return (alice.getN()==1&&bob.getN()==1)?result:-1;
    }
};