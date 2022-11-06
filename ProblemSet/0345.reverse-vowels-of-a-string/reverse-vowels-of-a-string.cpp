class Solution {
public:
    bool isVowels(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int a=0;
        int b=s.length()-1;
        while(a<b)
        {
            while(a<s.length()&&!isVowels(s[a]))
                a++;
            while(b>=0&&!isVowels(s[b]))
                b--;
            if(a>=b) break;
            swap(s[a],s[b]);
            a++;
            b--;
        }
        return s;
    }
};