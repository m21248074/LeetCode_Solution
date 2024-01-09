class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        unordered_map<char,int> um;
        for(string word:words)
        {
            for(char c:word)
                um[c]++;
        }
        for(auto i:um)
        {
            if(i.second%n)
                return false;
        }
        return true;
    }
};