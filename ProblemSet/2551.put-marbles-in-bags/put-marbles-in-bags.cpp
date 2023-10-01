class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> p;
        for(int i=0;i+1<n;i++)
            p.push_back(weights[i]+weights[i+1]);
        sort(p.begin(),p.end());
        long long result=0;
        for(int i=0;i<k-1;i++)
            result+=p[p.size()-1-i]-p[i];
        return result;
    }
};