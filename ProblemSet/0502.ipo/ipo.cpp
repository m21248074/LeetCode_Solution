class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> projects;
        for(int i=0;i<n;i++)
            projects.push_back(make_pair(capital[i],profits[i]));
        sort(projects.begin(),projects.end());
        int id=0;
        priority_queue<int> pq;
        for(int i=0;i<k;i++)
        {
            while(id<n&&projects[id].first<=w)
                pq.push(projects[id++].second);
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};