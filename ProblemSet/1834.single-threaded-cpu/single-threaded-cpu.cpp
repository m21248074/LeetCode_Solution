class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<int> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        long time=0;
        int i=0;
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        while(i<n||!pq.empty())
        {
            if(pq.empty())
                time=max(time,long(tasks[i][0]));
            while(i<n&&time>=tasks[i][0])
            {
                pq.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }
            pair<int,int> top=pq.top();
            pq.pop();
            time+=top.first;
            result.push_back(top.second);
        }
        return result;
    }
};