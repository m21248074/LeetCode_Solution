class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        int result=0;
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i==0||s[i-1]==s[i])
                count+=1;
            else
                count=1;
            result+=count;
            result%=mod;
        }
        return result;
    }
};