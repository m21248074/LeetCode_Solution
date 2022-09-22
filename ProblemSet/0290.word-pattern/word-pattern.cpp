class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> um1;
        unordered_map<string,char> um2;
        int n=pattern.length();
        int i=0;
        size_t pos;
        while((pos=s.find(' '))!=string::npos)
        {
            string token=s.substr(0,pos);
            if(!(um1.count(pattern[i]))&&!(um2.count(token)))
            {
                um1[pattern[i]]=token;
                um2[token]=pattern[i];
            }
            else if(um1.count(pattern[i])&&um1[pattern[i]]!=token)
                return false;
            else if(um2.count(token)&&um2[token]!=pattern[i])
                return false;
            s=s.substr(pos+1);
            i++;
        }
        if(um1.count(pattern[i])&&um1[pattern[i]]!=s)
            return false;
        else if(um2.count(s)&&um2[s]!=pattern[i])
            return false;
        i++;
        if(i!=n) return false;
        return true;
    }
};