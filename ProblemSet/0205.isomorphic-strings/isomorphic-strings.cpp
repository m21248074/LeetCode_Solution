class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1,m2;
        for(int i=0;i<s.length();i++)
        {
            char sChar=s.at(i),tChar=t.at(i);

            if(m1.find(sChar)==m1.end()) // can't find
                m1[sChar]=tChar;
            else if(m1[sChar]!=tChar)
                return false;

            if(m2.find(tChar)==m2.end())
                m2[tChar]=sChar;
            else if(m2[tChar]!=sChar)
                return false;
        }
        return true;
    }
};