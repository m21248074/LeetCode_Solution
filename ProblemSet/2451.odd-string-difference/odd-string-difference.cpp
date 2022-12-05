class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words.size();
        int l=words[0].length();
        map<vector<int>,vector<string>> m;
        for(int i=0;i<n;i++)
        {
            vector<int> result;
            for(int j=1;j<l;j++)
                result.push_back(words[i][j]-words[i][j-1]);
            m[result].push_back(words[i]);
        }
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->second.size()==1)
                return i->second[0];
        }
        return "";
    }
};