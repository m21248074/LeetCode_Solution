class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int i=0;
        int j=n-1;
        long long result=0;
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        while(k--)
        {
            while(pq1.size()<candidates&&i<=j)
                pq1.push(costs[i++]);
            while(pq2.size()<candidates&&i<=j)
                pq2.push(costs[j--]);
            int t1=pq1.size()>0?pq1.top():INT_MAX;
            int t2=pq2.size()>0?pq2.top():INT_MAX;
            if(t1<=t2)
            {
                result+=t1;
                pq1.pop();
            }
            else
            {
                result+=t2;
                pq2.pop();
            }
        }
        return result;
    }
};