class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int a=0,b=0;
        for(char c:s)
        {
            if(c=='0')
                b++;
            else
            {
                b=min(a,b);
                a++;
            }
        }
        return min(a,b);
    }
};