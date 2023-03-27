class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,unordered_map<int,int>> graph;
        for(auto connection:connections)
        {
            graph[connection[0]][connection[1]]=1;
            graph[connection[1]][connection[0]]=0;
        }
        unordered_set<int> visited;
        function<int(int)> dfs=[&](int cur)->int{
            int result=0;
            visited.insert(cur);
            for(auto i:graph[cur])
            {
                if(!visited.count(i.first))
                {
                    result+=i.second;
                    result+=dfs(i.first);
                }
            }
            return result;
        };
        return dfs(0);
    }
};