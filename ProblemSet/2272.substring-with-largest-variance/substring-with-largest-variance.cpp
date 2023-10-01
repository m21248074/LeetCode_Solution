class Solution {
public:
    int largestVariance(string s) {
        int result=0;
        int n=s.length();
        for(int a='a';a<='z';a++)
        {
            for(int b='a';b<='z';b++)
            {
                if(a==b)
                    continue;
                int diff=0;
                int diffWithB=-n;
                for(int i=0;i<n;i++)
                {
                    if(s[i]==a)
                    {
                        diff++;
                        diffWithB++;
                    }
                    else if(s[i]==b)
                    {
                        diff--;
                        diffWithB=diff;
                        diff=max(0,diff);
                    }
                    result=max(result,diffWithB);
                }
            }
        }
        return result;
    }
};