class DisjointSet
{
    private:
        vector<int> parent;
    public:
        DisjointSet(int size)
        {
            parent.resize(size,0);
            for(int i=0;i<size;i++) parent[i]=i;
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
            if(parentX==parentY)
                return;
            parent[parentY]=parentX;
        }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int result=n;
        map<int,vector<int>> value2nodes; // ordered
        vector<vector<int>> adjacency(n);
        for(int i=0;i<n;i++)
            value2nodes[vals[i]].push_back(i);
        for(auto edge:edges)
        {
            if(vals[edge[0]]>=vals[edge[1]])
                adjacency[edge[0]].push_back(edge[1]);
            if(vals[edge[0]]<=vals[edge[1]])
                adjacency[edge[1]].push_back(edge[0]);
        }
        DisjointSet ds(n);
        for(auto i:value2nodes)
        {
            int value=i.first;
            for(int node:i.second)
            {
                for(int neighbor:adjacency[node])
                    ds.join(node,neighbor);
            }
            unordered_map<int,int> group2size;
            for(int node:i.second)
                group2size[ds.find(node)]++;
            for(auto groupInfo:group2size)
            {
                int size=groupInfo.second;
                if(size>1)
                    result+=(size*(size-1))/2;
            }
        }
        return result;
    }
};