class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int result=0;
        unordered_map<int,vector<int>> stopToBus;
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
                stopToBus[routes[i][j]].push_back(i);
        }

        queue<int> q;
        q.push(source);
        unordered_set<int> visited;
        while(!q.empty())
        {
            result++;
            for(int i=q.size();i>0;i--)
            {
                int stop=q.front();
                q.pop();
                for(int bus:stopToBus[stop])
                {
                    if(visited.count(bus)) continue;
                    visited.insert(bus);
                    for(int st:routes[bus])
                    {
                        if(st==target) return result;
                        q.push(st);
                    }
                }
            }
        }
        return -1;
    }
};