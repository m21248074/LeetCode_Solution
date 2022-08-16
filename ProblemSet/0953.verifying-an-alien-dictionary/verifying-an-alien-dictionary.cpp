class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> um;
        for(int i=0;i<order.length();i++)
            um[order[i]]=i;
        for(string &word:words)
        {
            for(char &c:word)
                c=um[c];
        }
        return is_sorted(words.begin(),words.end());
    }
};