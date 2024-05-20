class Solution {
public:
    int maxDepth(string s) {
        int left=0;
        int result=0;
        for(char c:s)
        {
            if(c=='(')
            {
                left++;
                result=max(result,left);
            }
            else if(c==')')
                left--;
        }
        return result;
    }
};