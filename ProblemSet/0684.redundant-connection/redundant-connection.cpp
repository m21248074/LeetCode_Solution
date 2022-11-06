class DisjointSet
{
    private:
        map<int,int> parent;
    public:
        int find(int x)
        {
            if(!parent.count(x))
                parent[x]=x;
            else if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }
        bool unionSets(int x,int y)
        {
            int parentX=find(x);
            int parentY=find(y);
            if(parentX==parentY)
                return false;
            parent[parentX]=parentY;
            return true;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds;
        for(auto edge:edges)
        {
            if(!ds.unionSets(edge[0],edge[1]))
                return edge;
        }
        return {};
    }
};