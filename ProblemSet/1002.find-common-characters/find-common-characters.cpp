class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string> result;
        vector<int> cnt(26,INT_MAX);
        for(string word:words)
        {
            vector<int> t(26);
            for(char c:word)
                t[c-'a']++;
            for(int i=0;i<26;i++)
                cnt[i]=min(cnt[i],t[i]);
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<cnt[i];j++)
                result.push_back(string(1,'a'+i));
        }
        return result;
    }
};