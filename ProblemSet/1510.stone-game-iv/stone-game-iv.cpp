class Solution {
private:
    using ll = long long;
    int dp[100001];

    bool solve(int n){
        if(n == 0) return false;

        if(dp[n] != -1) return dp[n];

        // Both loop is working fine but upper one may tle because it will check again n again for nums like 2,3,5,6... 
        // that are invalid that will check for that too so in computing that will be slow that's why i avoided that..
        
        for(int i=1; i*i<=n; i++){
            if(!solve(n-(i*i))) return dp[n] = true;
        }

        return dp[n] = false;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};