class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int result=0;
        int n=arr.size();
        int mod=1e9+7;
        stack<int> s;
        s.push(-1);
        vector<int> dp(n+1,0);
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1&&arr[i]<=arr[s.top()])
                s.pop();
            dp[i+1]=(dp[s.top()+1]+(i-s.top())*arr[i])%mod;
            result=(result+dp[i+1])%mod;
            s.push(i);
        }
        return result;
    }
};