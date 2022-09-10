class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> indegree(numCourses);
        for(auto p:prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(!indegree[i]) q.push(i);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            result.push_back(node);
            for(int other:graph[node])
            {
                indegree[other]--;
                if(!indegree[other]) q.push(other);
            }
        }
        if(result.size()!=numCourses) result.clear();
        return result;
    }
};