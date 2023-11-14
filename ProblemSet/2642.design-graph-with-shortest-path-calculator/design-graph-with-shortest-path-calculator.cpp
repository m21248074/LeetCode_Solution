class Graph {
private:
    int n;
    vector<vector<int>> g;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n=n;
        g=vector<vector<int>>(n,vector<int>(n,INT_MAX/2));
        for(auto &edge:edges)
        {
            int s=edge[0];
            int e=edge[1];
            int w=edge[2];
            g[s][e]=w;
        }
    }
    
    void addEdge(vector<int> edge) {
        int s=edge[0];
        int e=edge[1];
        int w=edge[2];
        g[s][e]=w;
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool> visited(n);
        vector<int> distance(n,INT_MAX/2);
        distance[node1]=0;
        for(int i=0;i<n;i++)
        {
            int t=-1;
            for(int j=0;j<n;j++)
            {
                if(!visited[j]&&(t==-1||distance[t]>distance[j]))
                    t=j;
            }
            visited[t]=true;
            for(int j=0;j<n;j++)
                distance[j]=min(distance[j],distance[t]+g[t][j]);
        }
        return distance[node2]>=INT_MAX/2?-1:distance[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */