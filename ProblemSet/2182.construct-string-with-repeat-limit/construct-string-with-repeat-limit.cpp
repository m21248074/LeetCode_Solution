class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> um;
        for(char c:s)
            um[c]++;
        string result;

        for(char c='z';c>=0;)
        {
            if(um[c]==0)
            {
                c--;
                continue;
            }
            int t=min(um[c],repeatLimit);
            result.append(t, c);
            um[c] -= t;
            if(um[c]>0)
            {
                char d=c-1;
                while(d>='a'&&um[d]==0)
                    d--;
                if(d<'a')
                    break;
                result.push_back(d);
                um[d]--;
            }
        }
        return result;
    }
};