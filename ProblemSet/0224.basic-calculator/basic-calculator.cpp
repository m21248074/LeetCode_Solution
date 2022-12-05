class Solution {
public:
    int calculate(string s) {
        int result=0;
        int n=s.length();
        stack<int> st;
        int sign=1;
        for(int i=0;i<n;i++)
        {
            char c=s[i];
            if(c>='0')
            {
                int num=0;
                while(i<n&&s[i]>='0')
                    num=10*num+(s[i++]-'0');
                result+=sign*num;
                i--;
            }
            else if(c=='+')
                sign=1;
            else if(c=='-')
                sign=-1;
            else if(c=='(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(c==')')
            {
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
        }
        return result;
    }
};