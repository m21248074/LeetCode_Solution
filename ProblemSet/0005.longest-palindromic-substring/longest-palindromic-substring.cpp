class Solution {
public:
    string palindrome(string s,int l,int r)
    {
        while(l>=0&&r<s.size()&&s.at(l)==s.at(r))
            l--,r++;
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        string result="";
        for(int i=0;i<s.size();i++)
        {
            string a=palindrome(s,i,i);
            string b=palindrome(s,i,i+1);
            result=(a.size()>result.size())?a:result;
            result=(b.size()>result.size())?b:result;
        }
        return result;
    }
};