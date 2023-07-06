class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            double weight=-log(succProb[i]);
            graph[edges[i][0]].emplace_back(edges[i][1],weight);
            graph[edges[i][1]].emplace_back(edges[i][0],weight);
        }
        vector<double> distances(n,FLT_MAX);
        priority_queue<pair<double,int>> pq;
        pq.emplace(-0.0,start);
        vector<bool> visited(n,false);
        while(!pq.empty())
        {
            double distance=-pq.top().first;
            int u=pq.top().second;
            pq.pop();
            visited[u]=true;
            if(u==end) return exp(-distance);
            for(const auto& i:graph[u])
            {
                int v=i.first;
                double weight=i.second;
                if(visited[v]||distance+weight>distances[v]) continue;
                pq.emplace(-(distances[v]=distance+weight),v);
            }
        }
        return 0;
    }
};