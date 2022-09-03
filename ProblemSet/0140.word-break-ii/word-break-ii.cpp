class Solution {
public:
    void dp(string s,int i,unordered_set<string>& wordDict,vector<string>& result,vector<string>& track)
    {
        if(i==s.length())
        {
            string t;
            for(string word:track)
            {
                if(t=="")
                    t.append(word);
                else
                    t.append(" "+word);
            }
            result.push_back(t);
        }
        for(string word:wordDict)
        {
            int len=word.length();
            string temp=s.substr(i,len);
            if(word==temp)
            {
                track.push_back(word);
                dp(s,i+len,wordDict,result,track);
                track.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        vector<string> result;
        vector<string> track;
        for(string word:wordDict) us.insert(word);
        dp(s,0,us,result,track);
        return result;
    }
};