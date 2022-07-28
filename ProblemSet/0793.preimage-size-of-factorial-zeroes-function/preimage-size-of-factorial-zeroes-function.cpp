class Solution {
public:
    long trailingZeroes(long n) {
        long result=0;
        long divider=5;
        while(divider<=n)
        {
            result+=n/divider;
            divider*=5;
        }
        return result;
    }
    long left_bound(int target)
    {
        long left=0,right=LONG_MAX;
        while(left<right)
        {
            long mid=(left+right)/2;
            long result=trailingZeroes(mid);
            if(result==target)
                right=mid;
            else if(result<target)
                left=mid+1;
            else // result>target
                right=mid;
        }
        return left;
    }
    long right_bound(int target)
    {
        long left=0,right=LONG_MAX;
        while(left<right)
        {
            long mid=(left+right)/2;
            long result=trailingZeroes(mid);
            if(result==target)
                left=mid+1;
            else if(result<target)
                left=mid+1;
            else // result>target
                right=mid;
        }
        return left-1;
    }
    int preimageSizeFZF(int k) {
        return right_bound(k)-left_bound(k)+1;
    }
};