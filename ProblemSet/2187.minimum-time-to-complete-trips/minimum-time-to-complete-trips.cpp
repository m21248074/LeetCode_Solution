class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long minTime=*min_element(time.begin(),time.end());
        long left=0;
        long right=minTime*totalTrips;
        function<long(long)> helper=[&](long mid)->long{
            long result=0;
            for(int t:time)
                result+=mid/t;
            return result;
        };
        while(left<right)
        {
            long mid=(left+right)/2;
            if(helper(mid)<totalTrips)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};