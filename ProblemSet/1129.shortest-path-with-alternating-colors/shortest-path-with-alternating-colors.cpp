class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> result(n,-1);
        vector<vector<pair<int,int>>> graph(n);
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        for(auto edge:redEdges)
            graph[edge[0]].emplace_back(edge[1],1);
        for(auto edge:blueEdges)
            graph[edge[0]].emplace_back(edge[1],-1);
        int step=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                if(result[temp.first]==-1)
                    result[temp.first]=step;
                for(auto &i:graph[temp.first])
                {
                    if(i.first==-1||i.second==temp.second)
                        continue;
                    q.emplace(i.first,i.second);
                    i.first=-1;
                }
            }
            step++;
        }
        return result;
    }
};