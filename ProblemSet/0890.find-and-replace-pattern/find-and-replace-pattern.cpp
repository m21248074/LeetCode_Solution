class Solution {
public:
    bool check(string target,string pattern)
    {
        map<char,char> m1;
        map<char,char> m2;
        for(int i=0;i<target.length();i++)
        {
            char a=m1[target.at(i)];
            char b=m2[pattern.at(i)];
            if(!a&&!b)
            {
                m1[target.at(i)]=pattern.at(i);
                m2[pattern.at(i)]=target.at(i);
            }
            else if(a!=pattern.at(i))
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(int i=0;i<words.size();i++)
        {
            if(check(words[i],pattern))
                result.push_back(words[i]);
        }
        return result;
    }
};