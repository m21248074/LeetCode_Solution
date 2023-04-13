class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss;
        ss<<path;
        stack<string> s;
        string result;
        string temp;
        while(getline(ss,temp,'/'))
        {
            if(temp==""||temp==".") continue;
            if(temp==".."&&!s.empty())
                s.pop();
            else if(temp!="..")
                s.push(temp);
        }
        while(!s.empty())
        {
            temp=s.top();
            s.pop();
            result="/"+temp+result;
        }
        return !result.length()?"/":result;
    }
};