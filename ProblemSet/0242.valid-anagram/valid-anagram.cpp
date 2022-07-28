class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s.at(i)]++;
        for(int i=0;i<t.length();i++)
            m[t.at(i)]--;
        auto iter=m.begin();
        while(iter!=m.end())
        {
            if(iter->second!=0)
                return false;
            iter++;
        }
        return true;
    }
};