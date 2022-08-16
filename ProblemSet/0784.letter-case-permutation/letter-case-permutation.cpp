class Solution {
public:
    void helper(vector<string> &result,string &s,int index)
    {
        if(index>=s.length())
            result.push_back(s);
        else if(isalpha(s.at(index)))
        {
            helper(result,s,index+1);
            s[index]=(isupper(s[index]))?tolower(s[index]):toupper(s[index]);
            helper(result,s,index+1);
        }
        else
            helper(result,s,index+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        helper(result,s,0);
        return result;
    }
};