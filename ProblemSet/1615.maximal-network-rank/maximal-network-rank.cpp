class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int len=roads.size();
        int result=INT_MIN;
        int rank=INT_MIN;
        vector<int> edges(n+1);
        vector<vector<bool>> adj(n+1,vector<bool>(n+1));
        for(int i=0;i<len;i++)
        {
            int from=roads[i][0];
            int to=roads[i][1];
            edges[from]++;
            edges[to]++;
            adj[from][to]=true;
            adj[to][from]=true;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                rank=edges[i]+edges[j]-(adj[i][j]?1:0);
                result=max(result,rank);
            }
        }
        return result;
    }
};