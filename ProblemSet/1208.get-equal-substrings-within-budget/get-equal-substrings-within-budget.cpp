class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result=0;
        int n=s.size();
        int cur=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            cur+=abs(s[i]-t[i]);
            while(cur>maxCost&&start<=i)
            {
                cur-=abs(s[start]-t[start]);
                start++;
            }
            result=max(result,i-start+1);
        }
        return result;
    }
};
