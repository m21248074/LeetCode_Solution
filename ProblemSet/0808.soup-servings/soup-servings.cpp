class Solution {
public:
    double soupServings(int n) {
        vector<vector<double>> memo(200,vector<double>(200));
        function<double(int,int)> helper=[&](int a,int b)->double{
            if(a<=0&&b<=0) return 0.5;
            if(a<=0) return 1.0;
            if(b<=0) return 0;
            if(memo[a][b]>0) return memo[a][b];
            memo[a][b]=0.25*(helper(a-4,b)+helper(a-3,b-1)+helper(a-2,b-2)+helper(a-1,b-3));
            return memo[a][b];
        };
        return n>=4800?1:helper((n+24)/25,(n+24)/25);
    }
};