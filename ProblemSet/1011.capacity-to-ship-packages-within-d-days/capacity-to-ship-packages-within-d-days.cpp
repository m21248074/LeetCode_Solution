class Solution {
public:
    int double_max(int a,int b)
    {
        return (a>b)?a:b;
    }
    int f(vector<int>& weights,int x)
    {
        int p=0,days=0;
        while(p<weights.size())
        {
            int capacity=x;
            while(p<weights.size())
            {
                if(capacity-weights[p]>=0)
                {
                    capacity-=weights[p];
                    p++;
                }
                else
                    break;
            }
            days++;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0,right=1;
        for(int i=0;i<weights.size();i++)
        {
            left=double_max(left,weights[i]);
            right+=weights[i];
        }
        while(left<right)
        {
            int mid=(left+right)/2;
            int result=f(weights,mid);
            if(result==days)
                right=mid;
            else if(result<days)
                right=mid;
            else // result>days
                left=mid+1;
        }
        return left;
    }
};