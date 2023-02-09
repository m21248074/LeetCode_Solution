class Solution {
public:
    void helper(vector<vector<int>> graph,vector<vector<int>> &result,vector<int> &path,int i,int n)
    {
        path.push_back(i);
        if(i==n-1)
            result.push_back(path);
        else
        {
            for(int j=0;j<graph[i].size();j++)
                helper(graph,result,path,graph[i][j],n);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n=graph.size();
        vector<int> path;
        helper(graph,result,path,0,n);
        return result;
    }
};