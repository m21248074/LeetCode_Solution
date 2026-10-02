class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(!isdigit(c))
                st.push(c);
            else
                st.pop();
        }
        string result="";
        int n=st.size();
        for(int i=0;i<n;i++)
        {
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};