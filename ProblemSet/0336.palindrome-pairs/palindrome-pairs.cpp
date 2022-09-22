class Solution {
public:
    bool helper(string str,int left,int right)
    {
        while(left<right)
            if(str[left++]!=str[right--]) return false;
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string,int> um;
        set<int> s;
        for(int i=0;i<words.size();i++)
        {
            string word=words[i];
            um[word]=i;
            s.insert(word.length());
        }
        for(int i=0;i<words.size();i++)
        {
            string t=words[i];
            reverse(t.begin(),t.end());
            if(um.count(t)&&t!=words[i])
                result.push_back({i,um[t]});
            auto loc=s.find(t.length());
            for(auto j=s.begin();j!=loc;j++)
            {
                int len=*j;
                if(helper(t,0,t.length()-len-1)&&um.count(t.substr(t.length()-len)))
                    result.push_back({i,um[t.substr(t.length()-len)]});
                if(helper(t,len,t.length()-1)&&um.count(t.substr(0,len)))
                    result.push_back({um[t.substr(0,len)],i});
            }
        }
        return result;
    }
};