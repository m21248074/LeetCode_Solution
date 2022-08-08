class Solution {
public:
    string decodeString(string s) {
        stack<int> s1;
        stack<string> s2;
        int number=0;
        string str;
        for(int i=0;i<s.length();i++)
        {
            char c=s.at(i);
            if(isdigit(c))
                number=number*10+c-'0';
            else if(c=='[')
            {
                s1.push(number);
                s2.push(str);
                number=0;
                str="";
            }
            else if(c==']')
            {
                int temp=s1.top();
                s1.pop();
                for(int j=0;j<temp;j++)
                    s2.top()+=str;
                str=s2.top();
                s2.pop();
            }
            else // c is alpha
                str+=c;
        }
        return s2.empty()?str:s2.top();
    }
};