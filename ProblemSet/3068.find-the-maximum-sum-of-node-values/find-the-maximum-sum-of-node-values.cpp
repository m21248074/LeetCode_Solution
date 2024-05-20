class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result=0;
        int count=0;
        int pMin=INT_MAX;
        int nMax=INT_MIN;
        for(int num:nums)
        {
            int after=num^k;
            result+=num;
            int delta=after-num;
            if(delta>0)
            {
                pMin=min(pMin,delta);
                result+=delta;
                count++;
            }
            else
                nMax=max(nMax,delta);
        }
        if(count%2==0)
            return result;
        return max(result-pMin,result+nMax);
    }
};