class Solution {
public:
    int minimumOneBitOperations(int n) {
        function<int(int)> dfs=[&](int n)->int{
            if(n==0) return 0;
            int k=1;
            while(k<<1<=n)
                k<<=1;
            return dfs(k^(k>>1)^n)+k;
        };
        return dfs(n);
    }
};