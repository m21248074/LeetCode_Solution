class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<int,int> a,b;
        vector<int> aa,bb;
        for(char c:word1)
            a[c]++;
        for(char c:word2)
            b[c]++;
        for(auto i:a)
            if(!b[i.first]) return false;
        for(auto i:b)
            if(!a[i.first]) return false;
        for(auto i:a)
            aa.push_back(i.second);
        for(auto i:b)
            bb.push_back(i.second);
        sort(aa.begin(),aa.end());
        sort(bb.begin(),bb.end());
        for(int i=0;i<aa.size();i++)
            if(aa[i]!=bb[i]) return false;
        return true;
    }
};