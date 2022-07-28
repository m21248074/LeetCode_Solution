class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x,y;
        x=y=0;
        while(x<s.length()&&y<t.length())
        {
            if(s.at(x)==t.at(y))
                x++;
            y++;
        }
        return x==s.length();
    }
};