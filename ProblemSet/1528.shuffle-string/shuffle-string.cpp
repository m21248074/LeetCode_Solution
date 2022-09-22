class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        vector<char> t(n);
        for(int i=0;i<n;i++)
            t[indices[i]]=s[i];
        string result;
        for(char c:t)
            result.push_back(c);
        return result;
    }
};
