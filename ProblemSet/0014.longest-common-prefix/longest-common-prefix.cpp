class Solution {
public:
    bool isPrefix(string str,string prefix)
    {
        string t=str.substr(0,prefix.length());
        return t==prefix;
    }
    void helper(vector<string>& strs,string& prefix,int i)
    {
        if(i==strs.size()||prefix=="") return;
        if(isPrefix(strs[i],prefix))
            helper(strs,prefix,i+1);
        else
        {
            prefix.pop_back();
            helper(strs,prefix,i);
        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        helper(strs,prefix,0);
        return prefix;
    }
};