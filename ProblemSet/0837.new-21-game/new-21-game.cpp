class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k==0||n>=k+maxPts) return 1.0;
        vector<double> sum(k+maxPts);
        sum[0]=1.0;
        for(int i=1;i<k+maxPts;i++)
        {
            int t=min(i-1,k-1);
            if(i<=maxPts)
                sum[i]=sum[i-1]+sum[t]/maxPts;
            else
                sum[i]=sum[i-1]+(sum[t]-sum[i-maxPts-1])/maxPts;
        }
        return (sum[n]-sum[k-1])/(sum[k+maxPts-1]-sum[k-1]);
    }
};