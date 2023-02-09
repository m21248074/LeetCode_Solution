class DisjointSet
{
    private:
        vector<int> data;
    public:
        DisjointSet(int n)
        {
            data=vector<int>(n,0);
            for(int i=0;i<n;i++)
                data[i]=i;
        }
        int find(int x)
        {
            if(x!=data[x])
                data[x]=find(data[x]);
            return data[x];
        }
        void unionSet(int x,int y)
        {
            int rootX=find(x);
            int rootY=find(y);
            if(rootX==rootY)
                return;
            data[y]=rootX;
        }

};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> um;
        DisjointSet ds(n+1);
        for(auto dislike:dislikes)
        {
            um[dislike[0]].push_back(dislike[1]);
            um[dislike[1]].push_back(dislike[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(!um.count(i)) continue;
            int x=ds.find(i);
            int y=ds.find(um[i][0]);
            if(x==y) return false;
            for(int j=1;j<um[i].size();j++)
            {
                int parent=ds.find(um[i][j]);
                if(x==parent) return false;
                ds.unionSet(y,parent);
            }
        }
        return true;
    }
};