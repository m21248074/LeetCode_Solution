class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> um;
        int i;
        for(i=0;i<s.length();i++)
        {
            um[s.at(i)]++;
            um[t.at(i)]--;
        }
        um[t.at(i)]--;
        for(auto i=um.begin();i!=um.end();i++)
        {
            if(i->second==-1)
                return i->first;
        }
        return 0;
    }
};