class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> um;
        for(char c:chars)
            um[c]++;
        int result=0;
        for(string word:words)
        {
            unordered_map<char,int> um_word;
            for(char c:word)
                um_word[c]++;
            if(um.size()<um_word.size())
                continue;
            // >=
            bool pass=true;
            for(auto i:um_word)
            {
                if(um[i.first]<i.second)
                {
                    pass=false;
                    break;
                }
            }
            if(pass)
                result+=word.length();
        }
        return result;
    }
};