class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char c:s)
        {
            if(isalpha(c))
                t.push_back(tolower(c));
            else if(isalnum(c))
                t.push_back(c);
        }
        if(!t.length()) return true;
        int i=0,j=t.length()-1;
        while(i<=j)
            if(t[i++]!=t[j--]) return false;
        return true;
    }
};