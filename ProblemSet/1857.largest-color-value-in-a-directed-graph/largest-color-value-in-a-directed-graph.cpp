class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0); // indegree counter
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        int result=1;
        queue<int> q;
        vector<vector<int>> m(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
                m[i][colors[i]-'a']++;
            }
        }
        int counter=0;
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            counter++;
            for(int i:graph[t])
            {
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
                for(int j=0;j<26;j++)
                {
                    m[i][j]=max(m[i][j],m[t][j]+(colors[i]-'a'==j));
                    result=max(result,m[i][j]);
                }
            }
        }
        if(counter<n) // contains cycle(s)
            return -1;
        return result;
    }
};