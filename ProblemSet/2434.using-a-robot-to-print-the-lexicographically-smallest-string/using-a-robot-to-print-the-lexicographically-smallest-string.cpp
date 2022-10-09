class Solution {
public:
    string robotWithString(string s) {
        string p;
        string t;
        map<char,int> m;
        for(char c:s)
            m[c]++;
        for(char c:s)
        {
            t.push_back(c);
            m[c]--;
            char smallest=c;
            for(auto i=m.begin();i!=m.end();i++)
            {
                if(i->second!=0)
                {
                    smallest=i->first;
                    break;
                }
            }
            while(!t.empty()&&t.back()<=smallest)
            {
                p.push_back(t.back());
                t.pop_back();
            }
        }
        reverse(t.begin(),t.end());
        return p+t;
    }
};