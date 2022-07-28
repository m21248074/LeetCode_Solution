class Solution {
public:
    int f(vector<int>& piles,int x)
    {
        int sum=0;
        for(int i=0;i<piles.size();i++)
            sum+=(piles[i]%x)?piles[i]/x+1:piles[i]/x;
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=1000000000+1;

        while(left<right)
        {
            int mid=(left+right)/2;
            int result=f(piles,mid);
            if(result<=h)
                right=mid;
            else // result>h
                left=mid+1;
        }
        return left;
    }
};