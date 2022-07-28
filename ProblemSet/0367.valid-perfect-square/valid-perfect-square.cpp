class Solution {
public:
    long square(long v)
    {
        return v*v;
    }
    bool isPerfectSquare(int num) {
        int left=0,right=num;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(square(mid)==num)
                return true;
            else if(square(mid)>num)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
};