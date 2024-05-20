class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left=0;
        int n=s.length();
        for(char &c:s)
        {
            if(c=='(')
                left++;
            else if(c==')')
            {
                if(left)
                    left--;
                else
                    c='*';
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(left>0&&s[i]=='(')
            {
                s[i]='*';
                left--;
            }
        }
        string result;
        for(char c:s)
        {
            if(c!='*')
                result+=c;
        }
        return result;
    }
};