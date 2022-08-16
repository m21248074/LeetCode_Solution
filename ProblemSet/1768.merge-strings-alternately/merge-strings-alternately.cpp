class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        auto p1=word1.begin();
        auto p2=word2.begin();
        while(p1!=word1.end()&&p2!=word2.end())
        {
            result.push_back(*p1);
            result.push_back(*p2);
            p1++;
            p2++;
        }
        if(p1!=word1.end())
        {
            while(p1!=word1.end())
            {
                result.push_back(*p1);
                p1++;
            }
        }
        else if(p2!=word2.end())
        {
            while(p2!=word2.end())
            {
                result.push_back(*p2);
                p2++;
            }
        }
        return result;
    }
};