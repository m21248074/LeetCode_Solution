class Solution {
public:
    int nthUglyNumber(int n) {
        int u2,u3,u5;
        int p2,p3,p5;
        u2=u3=u5=1;
        p2=p3=p5=0;
        vector<int> result;
        while(result.size()<n)
        {
            int t=min(min(u2,u3),u5);
            result.push_back(t);
            if(u2==t)
            {
                u2=2*result[p2];
                p2++;
            }
            if(u3==t)
            {
                u3=3*result[p3];
                p3++;
            }
            if(u5==t)
            {
                u5=5*result[p5];
                p5++;
            }
        }
        return result[n-1];
    }
};