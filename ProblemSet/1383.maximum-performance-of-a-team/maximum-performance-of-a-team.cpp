class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second>b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers;
        for(int i=0;i<n;i++)
            engineers.push_back(pair<int,int>(speed[i],efficiency[i]));
        sort(engineers.begin(),engineers.end(),cmp); // efficiency
        long long result=0;
        int mod=pow(10,9)+7;
        long long speedSum=0;
        priority_queue<int,vector<int>,greater<int>> pq; // speed
        for(auto engineer:engineers)
        {
            if(pq.size()==k)
            {
                speedSum-=pq.top();
                pq.pop();
            }
            pq.push(engineer.first);
            speedSum+=engineer.first;
            result=max(result,speedSum*engineer.second);
        }
        return result%mod;
    }
};