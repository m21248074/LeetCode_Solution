class Solution {
public:
    void helper(int &cnt,int n)
    {
        if(n==1) return;
        cnt+=n/2;
        helper(cnt,n/2+n%2);
    }
    int numberOfMatches(int n) {
        int cnt=0;
        helper(cnt,n);
        return cnt;
    }
};