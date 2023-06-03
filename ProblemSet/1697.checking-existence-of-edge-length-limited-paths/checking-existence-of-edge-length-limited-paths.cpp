class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> result(queries.size(),0);
        for(int i=0;i<queries.size();i++)
            queries[i].push_back(i);
        vector<int> parent(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        function<int(int)> find=[&](int x)->int{
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        };
        function<void(int,int)> _union=[&](int x,int y){
            int rootX=find(x);
            int rootY=find(y);
            if(rootX<rootY)
                parent[rootY]=rootX;
            else
                parent[rootX]=rootY;
        };
        sort(edgeList.begin(),edgeList.end(),cmp);
        sort(queries.begin(),queries.end(),cmp);
        int i=0;
        for(auto query:queries)
        {
            while(i<edgeList.size()&&edgeList[i][2]<query[2])
            {
                int a=edgeList[i][0];
                int b=edgeList[i][1];
                if(find(a)!=find(b))
                    _union(a,b);
                i++;
            }
            result[query[3]]=(find(query[0])==find(query[1]));
        }
        return result;
    }
};