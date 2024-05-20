class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double result=DBL_MAX;
        int sum=0;
        int n=quality.size();
        vector<pair<double,int>> workers;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            workers.push_back({double(wage[i])/quality[i],quality[i]});
        sort(workers.begin(),workers.end());
        for(auto worker:workers)
        {
            sum+=worker.second;
            pq.push(worker.second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                result=min(result,sum*worker.first);
        }
        return result;
    }
};