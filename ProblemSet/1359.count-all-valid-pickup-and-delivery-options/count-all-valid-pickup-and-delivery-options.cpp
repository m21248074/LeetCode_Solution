class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        long long result=1;
        for(int i=2;i<=n;i++)
            result=(result*(2*i-1)*i)%mod;
        return result;
    }
};