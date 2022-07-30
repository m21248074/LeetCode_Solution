class Solution {
public:
    int double_max(int a,int b)
    {
        return a>b?a:b;
    }
    int longestPalindrome(string s) {
        set<char> m;
        for(int i=0;i<s.length();i++)
        {
            if(!m.count(s.at(i)))
                m.insert(s.at(i));
            else
                m.erase(s.at(i));
        }
        return s.length()-double_max(0,m.size()-1);
    }
};