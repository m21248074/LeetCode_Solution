class Solution {
public:
    int minSteps(int n) {
        // 1 -> n
        function<int(int,int)> helper=[&](int i,int j)->int{
            if(i==n)
                return 0;
            else if(i>n)
                return 1000;
            int copyPaste=2+helper(i*2,i);
            int onlyPaste=1+helper(i+j,j);
            return min(copyPaste,onlyPaste);
        };
        if(n==1) return 0;
        return 1+helper(1,1);
    }
};