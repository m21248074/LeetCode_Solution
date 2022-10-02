class Solution {
public:
    int minimizeXor(int a, int b) {
        int res=0;
        int setBits=__builtin_popcount(b);
        stack<int> s;
        while(a>0)
        {
            s.push(a%2);
            a=a/2;
        }
        vector<int> m;
        while(!s.empty())
        {
            if(s.top()==1 && setBits>0)
            {
                m.push_back(1);
                setBits--;
            }
            else
                m.push_back(0);
            s.pop();
        }
        for(int i=m.size()-1;i>=0 && setBits>0;i--)
        {
            if(m[i]==0)
            {
                m[i]=1;
                setBits--;
            }
        }
        int mask;
        for(int i=m.size()-1;i>=0;i--)
        {
            mask=1<<(m.size()-i-1);
            res+=m[i]*mask;
        }
        int n=m.size();
        while(setBits>0)
        {
            res+=1<<n;
            n++;
            setBits--;
        }
        return res;
    }
};