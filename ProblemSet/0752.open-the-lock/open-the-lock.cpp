class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string init="0000";
        if(target==init) return 0;
        unordered_set<string> us(deadends.begin(),deadends.end());
        if(us.count(init)) return -1;
        int result=0;
        unordered_set<string> visited;
        visited.insert(init);
        queue<string> q;
        q.push(init);
        while(!q.empty())
        {
            result++;
            for(int k=q.size();k>0;k--)
            {
                auto t=q.front();
                q.pop();
                for(int i=0;i<t.size();i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        if(j==0) continue;
                        string s=t;
                        s[i]=((t[i]-'0')+10+j)%10+'0';
                        if(s==target)
                            return result;
                        if(!visited.count(s)&&!us.count(s))
                            q.push(s);
                        visited.insert(s);
                    }
                }
            }
        }
        return -1;
    }
};