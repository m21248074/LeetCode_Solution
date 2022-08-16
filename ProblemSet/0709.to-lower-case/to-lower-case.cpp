class Solution {
public:
    char toLowerCase(char c)
    {
        return ('A'<=c&&c<='Z')?'a'+(c-'A'):c;
    }
    string toLowerCase(string s) {
        for(int i=0;i<s.length();i++)
            s[i]=toLowerCase(s[i]);
        return s;
    }
};