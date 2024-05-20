class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> result;
        vector<unordered_set<int>> vus(n);
        queue<int> q;
        for(auto edge:edges)
        {
            vus[edge[0]].insert(edge[1]);
            vus[edge[1]].insert(edge[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vus[i].size()==1)
            {
                cout << i << endl;
                q.push(i);
            }
        }
        while(n>2)
        {
            int size=q.size();
            n-=size;
            for(int i=0;i<size;i++)
            {
                int t=q.front();
                q.pop();
                for(auto j:vus[t])
                {
                    vus[j].erase(t);
                    if(vus[j].size()==1)
                        q.push(j);
                }
            }
        }
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};