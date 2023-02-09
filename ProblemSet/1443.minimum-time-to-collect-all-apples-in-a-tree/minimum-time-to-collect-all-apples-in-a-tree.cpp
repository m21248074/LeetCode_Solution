class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,vector<int>> m;
        for(auto edge:edges)
        {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        function<int(int)> helper=[&](int node)-> int {
            if(visited[node])
                return 0;
            visited[node]=true;
            int result=0;
            for(int i:m[node])
                result+=helper(i);
            if(result==0&&node!=0)
                return (hasApple[node])?2:0;
            return result+((node!=0)?2:0);
        };
        return helper(0);
    }
};