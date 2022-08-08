class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> a,b;
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)!='#')
                a.push(s.at(i));
            else
            {
                if(!a.empty())
                    a.pop();
            }
        }
        for(int i=0;i<t.length();i++)
        {
            if(t.at(i)!='#')
                b.push(t.at(i));
            else
            {
                if(!b.empty())
                    b.pop();
            }
        }
        while(!a.empty()||!b.empty())
        {
            if(a.empty()||b.empty()) return false;
            if(a.top()!=b.top())
                return false;
            a.pop();
            b.pop();
        }
        return true;
    }
};