class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        vector<long> u(m,1);
        vector<int> p(m,0);
        vector<long> result;
        while(result.size()<n)
        {
            priority_queue<long,vector<long>,greater<long>> pq;
            for(long t:u)
                pq.push(t);
            int t=pq.top();
            result.push_back(t);
            for(int i=0;i<u.size();i++)
            {
                if(u[i]==t)
                {
                    u[i]=primes[i]*result[p[i]];
                    p[i]++;
                }
            }
        }
        return result[n-1];
    }
};