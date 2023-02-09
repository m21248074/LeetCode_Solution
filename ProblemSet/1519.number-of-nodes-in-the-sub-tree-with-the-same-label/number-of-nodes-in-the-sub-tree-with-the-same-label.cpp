class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        map<int,vector<int>> m;
        for(auto edge:edges)
        {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        vector<int> count(n,0);
        unordered_map<char,int> um; // (label,count)
        function<void(int)> helper=[&](int node)-> void {
            if(visited[node])
                return;
            visited[node]=true;
            int pre=um[labels[node]];
            for(int i:m[node])
                helper(i);
            um[labels[node]]++;
            count[node]=um[labels[node]]-pre;
        };
        helper(0);
        return count;
    }
};