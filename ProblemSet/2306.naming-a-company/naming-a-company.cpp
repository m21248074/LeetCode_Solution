class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>> um;
        for(string idea:ideas)
            um[idea[0]].insert(idea.substr(1));
        long long result=0LL;
        for(int i=1;i<26;i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp=0;
                for(string s:um['a'+i])
                    temp+=um['a'+j].count(s);
                result+=(long)(um['a'+i].size()-temp)*(um['a'+j].size()-temp);
            }
        }
        return result*2;
    }
};