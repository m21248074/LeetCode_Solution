class Solution {
public:
    void helper(int left,int right,vector<string> &result,string cur)
    {
        if(left>right) return;
        else if(!left&&!right)
        {
            result.push_back(cur);
            return;
        }
        if(left>0)
            helper(left-1,right,result,cur+"(");
        if(right>0)
            helper(left,right-1,result,cur+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        helper(n,n,result,"");
        return result;
    }
};