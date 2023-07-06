class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left=index;
        int right=index;
        int level=1;
        int rest=maxSum-n;
        while(left>0||right<n-1)
        {
            int len=right-left+1;
            if(rest>=len)
            {
                rest-=len;
                level++;
                left=max(0,left-1);
                right=min(n-1,right+1);
            }
            else
                break;
        }
        level+=rest/n;
        return level;
    }
};