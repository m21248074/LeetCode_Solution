class Solution {
public:
    int longestContinuousSubstring(string s) {
        int left=0,right=0;
        int n=s.length();
        int result=0;
        while(right<n)
        {
            right++;
            if(s[right]-s[right-1]!=1)
            {
                left=right;
            }
            result=max(result,right-left+1);
        }
        return result;
    }
};