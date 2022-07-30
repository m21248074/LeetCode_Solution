class Solution {
public:
    vector<int> helper(string word)
    {
        vector<int> result(26,0);
        for(char w:word)
            result[w-'a']++;
        return result;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> words2Cnt(26,0);
        for(string word:words2)
        {
            vector<int> temp=helper(word);
            for(int i=0;i<26;i++)
                words2Cnt[i]=max(words2Cnt[i],temp[i]);
        }
        for(string word:words1)
        {
            bool isPass=true;
            vector<int> temp=helper(word);
            for(int i=0;i<26;i++)
            {
                if(words2Cnt[i]>temp[i])
                {
                    isPass=false;
                    break;
                }
            }
            if(isPass)
                result.push_back(word);
        }
        return result;
    }
};