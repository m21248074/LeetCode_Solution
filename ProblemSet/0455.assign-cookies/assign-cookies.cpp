class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int result=0;
        int p=0;
        for(int cookie:s)
        {
            if(cookie>=g[p])
            {
                result++;
                p++;
            }
            if(p==g.size())
                break;
        }
        return result;
    }
};