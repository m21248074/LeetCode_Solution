class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        int result=stoi(s);
        for(char &c:s)
        {
            char t=c;
            c=(c=='6')?'9':'6';
            result=max(result,stoi(s));
            c=t;
        }
        return result;
    }
};