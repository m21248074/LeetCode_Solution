class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        int n=graph.size();
        vector<bool> safe(n,false);
        vector<set<int>> g(n,set<int>()),revG=g;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(graph[i].empty())
                q.push(i);
            for(int j:graph[i])
            {
                g[i].insert(j);
                revG[j].insert(i);
            }
        }
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            safe[t]=true;
            for(int i:revG[t])
            {
                g[i].erase(t);
                if(g[i].empty())
                    q.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(safe[i])
                result.push_back(i);
        }
        return result;
    }
};