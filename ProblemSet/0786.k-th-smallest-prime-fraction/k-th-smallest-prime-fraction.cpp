class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++)
            pq.push({-1.0*arr[i]/arr.back(),{i,arr.size()-1}});
        while(--k)
        {
            auto t=pq.top().second;
            pq.pop();
            t.second--;
            pq.push({-1.0*arr[t.first]/arr[t.second],{t.first,t.second}});
        }
        return {arr[pq.top().second.first],arr[pq.top().second.second]};
    }
};