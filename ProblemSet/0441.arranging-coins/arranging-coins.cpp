class Solution {
public:
    int arrangeCoins(int n) {
        if(!n) return n;
        int i;
        for(i=1;i<=n;i++)
        {
            if(n<0)
                break;
            n-=i;
        }
        return i-1;
    }
};