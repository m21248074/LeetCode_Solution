class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            switch(s.at(i))
            {
                case '(':
                case '{':
                case '[':
                    st.push(s.at(i));
                    break;
                case ')':
                    if(!st.size()||st.top()!='(')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(!st.size()||st.top()!='{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(!st.size()||st.top()!='[')
                        return false;
                    st.pop();
                    break;
            }
        }
        return st.size()?false:true;
    }
};